/*
题目大意：
给定一个数组，求每个数字前面比自己小的数字的数量。

解题思路：
线段树。

遇到的问题：
没有。
*/
class Solution {
    struct SegmentTreeNode {
        int start, end, cnt;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e) {
            start = s;
            end = e;
            cnt = 0;
            left = right = NULL;
        }
    };
    
    void insert(SegmentTreeNode *root, int val) {
        if (root == NULL || val < root->start || val > root->end) return;
        root->cnt++;
        if (root->start == root->end) return;
        
        int mid = (root->start + root->end) / 2;
        if (root->left == NULL) root->left = new SegmentTreeNode(root->start, mid);
        if (root->right == NULL) root->right = new SegmentTreeNode(mid+1, root->end);
        
        insert(root->left, val);
        insert(root->right, val);
    }
    
    int count(SegmentTreeNode *root, int start, int end) {
        if (root == NULL || root->start > end || root->end < start) return 0;
        if (root->start >= start && root->end <= end) return root->cnt;
        return count(root->left, start, end) + count(root->right, start, end);
    }
    
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        SegmentTreeNode *root = new SegmentTreeNode(0, 10000);
        
        vector<int> ans(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            ans[i] = count(root, 0, A[i]-1);
            insert(root, A[i]);
        }
        
        return ans;
    }
};
