/*
题目大意：
给定一个二叉树，将其转化为链表。

解题思路：
既然是按照先序的顺序转化为链表。那么就是按照先序的反着的顺序遍历链表即可。

遇到的问题：
这个思路实在是太厉害了，看了别人的代码想了好一会才能明白。
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
    TreeNode *pre = NULL;
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        if (root == NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
};