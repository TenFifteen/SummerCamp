/*
题目：40 % 翻转二叉树 容易

题目大意：
给定一个二叉树，将其左右翻转

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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (root == NULL) return;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};
