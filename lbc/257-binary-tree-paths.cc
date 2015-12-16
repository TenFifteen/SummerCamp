/*
题目大意：
给定一个二叉树，返回所有路径的字符串表示。

解题思路：
递归

遇到的问题：
没有问题。一次通过。

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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return vector<string>();
        
        auto rleft = binaryTreePaths(root->left);
        auto rright = binaryTreePaths(root->right);
        
        vector<string> ans;
        for (auto i : rleft) {
            ans.push_back(to_string(root->val) + "->" + i);
        }
        for (auto i : rright) {
            ans.push_back(to_string(root->val) + "->" + i);
        }
        
        if (ans.size() == 0) {
            ans.push_back(to_string(root->val));
        }
        return ans;
    }
};