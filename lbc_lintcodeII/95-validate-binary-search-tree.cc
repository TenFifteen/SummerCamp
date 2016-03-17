/*
题目大意：
给定一个二叉树，验证其是否是二叉查找树。

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
    bool isValid(TreeNode *root, long long left, long long right) {
        if (root == NULL) return true;
        if (root->val <= left || root->val >= right) return false;
        
        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }
    
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        return isValid(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};