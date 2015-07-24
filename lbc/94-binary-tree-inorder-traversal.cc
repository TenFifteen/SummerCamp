/*
题目大意：
给出一个二叉树，进行中序遍历。要求不要递归。

解题思路：
用一个stack将需要后访问的节点存储起来。

遇到的问题：
我竟然用一个queue调试了老半天。
哎，真是挫啊。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return ans;
        stack<TreeNode *> q;
        q.push(root);
        set<TreeNode *> s;
        while(!q.empty()){
            TreeNode *cur = q.top();
            q.pop();
            if(cur->left == NULL || s.count(cur) != 0){
                ans.push_back(cur->val);
                if(cur->right != NULL){
                    q.push(cur->right);
                }
            }else{
                q.push(cur);
                q.push(cur->left);
                s.insert(cur);
            }
        }
        return ans;
    }
};