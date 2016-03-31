/*
题目大意：
给定两颗二叉树，问是否是一样的。

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
public:
    /**
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        if (a == NULL || b == NULL) return a == b;
        
        if (a->val != b->val) return false;
        
        return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    }
};