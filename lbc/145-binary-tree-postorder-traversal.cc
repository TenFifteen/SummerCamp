/*
题目大意：
给定一个二叉树，后序遍历，不能递归。

解题思路：
还是用stack将待访问的节点缓存住。

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> s;
        if(root != NULL){
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            root->left = NULL;
            root->right = NULL;
            s.push(root);
            if(right != NULL)s.push(right);
            if(left != NULL)s.push(left);
        }
        while(!s.empty()){
            TreeNode *cur = s.top();
            s.pop();
            if(cur->left == NULL && cur->right == NULL){
                ans.push_back(cur->val);
            }else{
                TreeNode *left = cur->left;
                TreeNode *right = cur->right;
                cur->left = NULL;
                cur->right = NULL;
                s.push(cur);
                if(right != NULL)s.push(right);
                if(left != NULL)s.push(left);
            }
        }
        return ans;
    }
};