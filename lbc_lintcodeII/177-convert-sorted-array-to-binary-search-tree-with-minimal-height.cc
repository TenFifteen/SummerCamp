/*
题目大意：
给定一个排序的数组，将其转化为二分搜索树，平衡树。

解题思路：
见代码。

遇到的问题：
没有。
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    TreeNode *build(vector<int> &A, int left, int right) {
        if (left > right) return NULL;
        
        int mid = left+(right-left)/2;
        TreeNode *ret = new TreeNode(A[mid]);
        ret->left = build(A, left, mid-1);
        ret->right = build(A, mid+1, right);
        return ret;
    }
    
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if (A.size() == 0) return NULL;
        return build(A, 0, A.size()-1);
    }
};


