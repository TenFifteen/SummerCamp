/*
题目：39 % 二叉树的中序遍历 容易

题目大意：
给定一个二叉树，中序遍历，非递归

解题思路：
用两个栈，分别存放没有访问的节点，和已经访问过左子树的节点

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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        vector<int> ans;
        if (root == NULL) return ans;
        stk1.push(root);
        while (!stk1.empty() || !stk2.empty()) {
            if (!stk1.empty()) {
                auto cur = stk1.top();
                stk1.pop();
                if (cur->left != NULL) {
                    stk1.push(cur->left);
                }
                stk2.push(cur);
            } else {
                auto cur = stk2.top();
                stk2.pop();
                ans.push_back(cur->val);
                if (cur->right != NULL) {
                    stk1.push(cur->right);
                }
            }
        }
        return ans;
    }
};
