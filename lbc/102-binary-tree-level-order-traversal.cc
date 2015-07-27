/*
题目大意：
给一个二叉树，返回其分层遍历的结果。

解题思路：
队列

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        queue<TreeNode *> q;
        q.push(root);
        sub(ans, q);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, queue<TreeNode *> q){
        queue<TreeNode *> next;
        vector<int> ret;
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            ret.push_back(cur->val);
            if(cur->left != NULL)next.push(cur->left);
            if(cur->right != NULL)next.push(cur->right);
        }
        ans.push_back(ret);
        if(!next.empty()){
            sub(ans, next);
        }
    }
};