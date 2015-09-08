/*
题目：23 % 二叉树中的最大路径和 中等

题目大意：
给定一个二叉树，求其中任意一条路的和最长

解题思路：
递归

遇到的问题：
一开始没有考虑到不是从叶子节点开始的路径和在子树中的路径。
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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        auto ret = sub(root);
        return ret.first;
    }
    
    pair<int, int> sub(TreeNode *root) {
        if (root == NULL) return make_pair(INT_MIN, INT_MIN);
        auto left = sub(root->left);
        auto right = sub(root->right);
        auto ret = make_pair(max(left.first, right.first), max(left.second, right.second));
        ret.second = max(ret.second, 0) + root->val;
        int tmp = root->val;
        if (left.second > 0) tmp += left.second;
        if (right.second > 0) tmp += right.second;
        ret.first = max(ret.first, tmp);
        return ret;
    }
};
