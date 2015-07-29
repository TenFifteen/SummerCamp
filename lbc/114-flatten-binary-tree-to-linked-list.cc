/*
题目大意：
给定一个二叉树，求出将其flatten成一个链表。
按照先序遍历的顺序

解题思路：
递归

遇到的问题：
记得左右节点的左子树都要置为NULL
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
    void flatten(TreeNode* root) {
        sub(root);
    }
    
    TreeNode *sub(TreeNode *root){
        if(root == NULL)return NULL;
        TreeNode *left = NULL, *right = NULL;
        if(root->left != NULL){
            left = sub(root->left);
        }
        if(root->right != NULL){
            right = sub(root->right);
        }
        root->left = NULL;
        root->right = NULL;
        if(left != NULL){
            root->right = left;
        }
        TreeNode *cur = root;
        while(cur->right != NULL)cur = cur->right;
        cur->right = right;
        return root;
    }
};