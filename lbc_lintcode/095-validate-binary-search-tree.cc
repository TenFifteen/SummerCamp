/*
题目：23 % 验证二叉查找树 中等

题目大意：
给定一个二叉树，验证是否是二叉查找树

解题思路：
递归

遇到的问题：
竟然想了这么久。
而且，题目竟然不允许相等。。
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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if (root == NULL) return true;
        return sub(root->left, INT_MIN, root->val) && sub(root->right, root->val, INT_MAX);
    }
    
    bool sub(TreeNode *root, int small, int big) {
        if (root == NULL) return true;
        if (root->val <= small || root->val >= big) return false;
        return sub(root->left, small, root->val) && sub(root->right, root->val, big);
    }
};
