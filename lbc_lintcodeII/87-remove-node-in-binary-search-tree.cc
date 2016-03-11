/*
题目大意：
给定一个二叉查找树，让删除其中一个为value的node

解题思路：
分情况讨论。见代码

遇到的问题：
一开始遇到这个问题还真有点懵逼啊。然后仔细想了想，就知道了。
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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if (root == NULL) return root;
        
        if (root->val == value) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->left == NULL) {
                auto del = root;
                root = root->right;
                delete del;
                return root;
            } else if (root->right == NULL) {
                auto del = root;
                root = root->left;
                delete del;
                return root;
            }
            
            TreeNode *pre = root->left;
            while (pre->right) pre = pre->right;
            swap(root->val, pre->val);
            
            root->left = removeNode(root->left, value);
            return root;
        }
        
        if (root->val < value) {
            root->right = removeNode(root->right, value);
        } else {
            root->left = removeNode(root->left, value);
        }
        
        return root;
    }
};