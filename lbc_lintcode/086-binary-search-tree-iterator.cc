/*
题目：30 % 二叉查找树迭代器 困难

题目大意：
给定一个二叉查找树，实现其迭代器

解题思路：
相当于是中序遍历

遇到的问题：
没有问题。
只是题目中说可以用O（1）的空间复杂度，不知道咋写。
也没找到网上别人有这种解法，回头再考虑吧

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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
private:
    stack<TreeNode *> stk;
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        while (root != NULL) {
            stk.push(root);
            root = root->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !stk.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        auto ret = stk.top();
        stk.pop();
        auto cur = ret->right;
        while (cur != NULL) {
            stk.push(cur);
            cur = cur->left;
        }
        return ret;
    }
};
