/*
题目：41 % 在二叉查找树中插入节点 容易

题目大意：
给定一个二叉查找树，插入一个节点

解题思路：
直接插

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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (root == NULL) return node;
        auto cur = root;
        while (true) {
            if (node->val < cur->val) {
                if (cur->left == NULL) {
                    cur->left = node;
                    break;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->right == NULL) {
                    cur->right = node;
                    break;
                } else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};
