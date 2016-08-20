/**
 * Problem: count a complete binary tree.
 * Solve: if it is full, return 2^h-1, else return 1+left+right
 * Tips: 1. there must be a time when it is full when the h is shrink
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        int countNodes(TreeNode* root) {
            int left = leftDepth(root), right = rightDepth(root);

            if (left == right) return (1 << left) - 1;
            return countNodes(root->left) + countNodes(root->right) + 1;
        }

        int leftDepth(TreeNode *root) {
            int h = 0;
            while (root) {
                root = root->left;
                ++h;
            }
            return h;
        }
        int rightDepth(TreeNode *root) {
            int h = 0;
            while (root) {
                root = root->right;
                ++h;
            }
            return h;
        }
};
