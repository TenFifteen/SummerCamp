/*
题目大意：
中序遍历二叉树。

解题思路：
见代码。

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
    void in(TreeNode *root, vector<int> &ans) {
        if (root == NULL) return;
        in(root->left, ans);
        ans.push_back(root->val);
        in(root->right, ans);
    }
    
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> ans;
        in(root, ans);
        return ans;
    }
};