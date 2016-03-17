/*
题目大意：
给定一个二叉树，实现其迭代器。

解题思路：
先序遍历。

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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
    stack<TreeNode *> stk;
    
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return stk.size() != 0;
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode *ret = stk.top();
        stk.pop();
        
        TreeNode *root = ret->right;
        while (root) {
            stk.push(root);
            root = root->left;
        }
        
        return ret;
    }
};