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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> ans;
        stack<TreeNode *> s;
        if (root) while (root) {
            s.push(root);
            root = root->left;
        }
        
        while (s.size() > 0) {
            TreeNode *cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            cur = cur->right;
            if (cur) while (cur) {
                s.push(cur);
                cur = cur->left;
            }
        }
        
        return ans;
    }
};