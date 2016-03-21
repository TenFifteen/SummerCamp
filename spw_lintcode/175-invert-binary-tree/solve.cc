/**
 * Problem: Invert a binary tree.
 * Solve: recursive.
 * Tips: no
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
        TreeNode *sub(TreeNode *root) {
            if (root == NULL) return NULL;

            TreeNode *left = sub(root->left);
            TreeNode *right = sub(root->right);

            root->right = left;
            root->left = right;

            return root;
        }
        /**
         * @param root: a TreeNode, the root of the binary tree
         * @return: nothing
         */
        void invertBinaryTree(TreeNode *root) {
            // write your code here
            root = sub(root);
        }
};
