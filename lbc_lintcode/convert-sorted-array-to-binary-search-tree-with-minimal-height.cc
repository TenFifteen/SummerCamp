/*
题目：33 % 把排序数组转换为高度最小的二叉搜索树 容易

题目大意：
给定一个排序的数组，将其转化为有最小高度的平衡二叉树。

解题思路：
递归

遇到的问题：
没有问题。
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
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if (A.size() == 0) return NULL;
        return sub(A, 0, A.size()-1);
    }
    
    TreeNode *sub(vector<int> &A, int left, int right) {
        if (left > right) return NULL;
        int mid = left + (right-left+1)/2;
        auto ret = new TreeNode(A[mid]);
        ret->left = sub(A, left, mid-1);
        ret->right = sub(A, mid+1, right);
        return ret;
    }
};



