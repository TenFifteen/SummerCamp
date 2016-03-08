/*
题目大意：
给定一颗二叉树，找到所有的从root到leaf的路径。

解题思路：
直接遍历。

遇到的问题：
没有。
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
    void getAllPaths(vector<string> &ans, string now, TreeNode *root) {
        if (root == NULL) return;
        
        if (now == "") now = to_string(root->val);
        else now += "->" + to_string(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(now);
        }
        
        getAllPaths(ans, now, root->left);
        getAllPaths(ans, now, root->right);
    }
    
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> ans;
        getAllPaths(ans, "", root);
        return ans;
    }
};