/*
题目大意：
给定一个二叉树，翻转它。

解题思路：
递归。

遇到的问题：
一次通过。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)return NULL;
        auto l = invertTree(root->left);
        auto r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};