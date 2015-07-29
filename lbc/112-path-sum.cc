/*
题目大意：
给定一个二叉树，求出其所有从根到叶子节点的路径中，是否有和为sum的路径。

解题思路：
递归

遇到的问题：
竟然root == NULL && sum == 0属于false的情况。。。

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)return false;
        if(root->left == NULL && root->right == NULL){
            return root->val == sum;
        }
        if(root->left == NULL){
            return hasPathSum(root->right, sum-root->val);
        }
        if(root->right == NULL){
            return hasPathSum(root->left, sum-root->val);
        }
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};