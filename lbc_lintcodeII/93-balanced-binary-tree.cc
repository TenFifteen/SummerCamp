/*
题目大意：
给定一个二叉树，问是否是高度平衡的。

解题思路：
见代码。

遇到的问题；
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
    pair<int, bool> balance(TreeNode *root) {
        if (root == NULL) return make_pair(0, true);
        auto L = balance(root->left);
        auto R = balance(root->right);
        if (L.second == false || R.second == false) return make_pair(0, false);
        if (abs(L.first-R.first) > 1) return make_pair(0, false);
        return make_pair(max(L.first, R.first)+1, true);
    }
    
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return balance(root).second;
    }
};