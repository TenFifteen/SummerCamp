/*
题目大意：
给一个二叉树，返回其深度。

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)return 0;
        return sub(root, 1);
    }
    
    int sub(TreeNode *root, int level){
        if(root == NULL)return level-1;
        return max(sub(root->left, level+1), sub(root->right, level+1));
    }
};