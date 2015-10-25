/*
题目：32 % Flatten Binary Tree to Linked List new 容易

题目大意：
给定一个二叉树，将其按照先序遍历的顺序转化成一个假的单链表

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
    void flatten(TreeNode *root) {
        // write your code here
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        flatten(root->left);
        flatten(root->right);
        auto left = root->left;
        auto right = root->right;
        root->left = NULL;
        if (left == NULL) return;
        if (right == NULL) {
            root->right = left;
            return;
        }
        root->right = left;
        while (left->right) {
            left = left->right;
        }
        left->right = right;
    }
};
