/*
题目大意：
给定一个二叉树，求出其所有路径中的和为sum的路径。

解题思路：
递归。

遇到的问题：
注意边界。
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        vector<int> cur;
        sub(ans, cur, root, sum);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &cur, TreeNode *root, int sum){
        cur.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                ans.push_back(cur);
            }
        }
        if(root->left != NULL)sub(ans, cur, root->left, sum-root->val);
        if(root->right != NULL)sub(ans, cur, root->right, sum-root->val);
        cur.pop_back();
    }
};