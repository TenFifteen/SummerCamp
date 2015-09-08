/*
题目：41 % 平衡二叉树 中等

题目大意：
给定一个二叉查找树，判断是否是平衡二叉树。
平衡的标准就是每个子树的左子树和右子树的高度相差不能大于1

解题思路：
递归直接求

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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        auto ret = sub(root);
        return ret.second;
    }
    
    pair<int, bool> sub(TreeNode *root) {
        if (root == NULL) return make_pair(0, true);
        auto left = sub(root->left);
        auto right = sub(root->right);
        if (left.second && right.second && abs(left.first-right.first) < 2) {
            return make_pair(max(left.first, right.first)+1, true);
        } else {
            return make_pair(max(left.first, right.first)+1, false);
        }
    }
};
