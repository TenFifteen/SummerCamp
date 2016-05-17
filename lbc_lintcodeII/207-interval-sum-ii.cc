/*
题目大意：
给定一个数组，不断的修改和查找区间和。

解题思路：
线段树。

遇到的问题；
没有。
*/
class Solution {
    struct SegmentTreeNode {
        int start, end;
        long long sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e) {
            start = s;
            end = e;
            left = right = NULL;
        }
    };
    
    SegmentTreeNode *build(const vector<int> &A, int start, int end) {
        if (start > end) return NULL;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start == end) {
            root->sum = A[start];
        } else {
            int mid = (start + end)/2;
            root->left = build(A, start, mid);
            root->right = build(A, mid+1, end);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }
    
    long long _query(SegmentTreeNode *root, int start, int end) {
        if (root == NULL || root->start > end || root->end < start) return 0;
        if (root->start >= start && root->end <= end) return root->sum;
        return _query(root->left, start, end) + _query(root->right, start, end);
    }
    
    void _modify(SegmentTreeNode *root, int index, int val) {
        if (root == NULL || root->start > index || root->end < index) return;
        if (root->start == root->end) {
            root->sum = val;
        } else {
            _modify(root->left, index, val);
            _modify(root->right, index, val);
            root->sum = root->left->sum + root->right->sum;
        }
    }
    
public:
    /* you may need to use some attributes here */
    SegmentTreeNode *root;

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        root = build(A, 0, A.size()-1);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return _query(root, start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        _modify(root, index, value);
    }
};

