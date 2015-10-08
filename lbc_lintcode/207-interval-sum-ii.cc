/*
题目：24 % 区间求和 II 困难

题目大意：
给定一个数组。然后有一些列操作，包括查询区间的和、修改某个元素的值

解题思路：
线段树

遇到的问题：
没有问题。
*/
class Solution {
public:
    /* you may need to use some attributes here */
    

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
    
private:
    struct SegmentTreeNode {
        int start, end;
        long long sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e, long long ss) {
            start = s;
            end = e;
            sum = ss;
        }
    };
    
    SegmentTreeNode *build(vector<int> &A, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            auto ret = new SegmentTreeNode(left, right, A[left]);
            return ret;
        }
        auto ret = new SegmentTreeNode(left, right, 0);
        ret->left = build(A, left, (left+right)/2);
        ret->right = build(A, (left+right)/2+1, right);
        ret->sum = ret->left->sum + ret->right->sum;
        return ret;
    }
    
    long long _query(SegmentTreeNode *root, int left, int right) {
        if (root == NULL) return 0;
        if (root->start >= left && root->end <= right) return root->sum;
        if (root->start > right || root->end < left) return 0;
        return _query(root->left, left, right) + _query(root->right, left, right);
    }
    
    void _modify(SegmentTreeNode *root, int index, int value) {
        if (root->start == root->end) {
            root->sum = value;
            return;
        }
        if (root->left->end >= index) {
            _modify(root->left, index, value);
        } else {
            _modify(root->right, index, value);
        }
        root->sum = root->left->sum + root->right->sum;
    }
    
    SegmentTreeNode *root;
};

