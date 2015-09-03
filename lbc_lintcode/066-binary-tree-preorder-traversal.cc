/*
题目：40 % 二叉树的前序遍历 容易

题目大意：
先序遍历二叉树，不用递归

解题思路：
用stack

遇到的问题：
没有问题。
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode *> stk;
        vector<int> ans;
        if (root == NULL) return ans;
        stk.push(root);
        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            ans.push_back(cur->val);
            if (cur->right != NULL) stk.push(cur->right);
            if (cur->left != NULL) stk.push(cur->left);
        }
        return ans;
    }
};

