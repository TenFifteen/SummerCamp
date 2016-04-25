/**
 * Problem: Given a binary search tree and a new tree node, insert
 *          the node into the tree. You should keep the tree still
 *          be a valid binary search tree.
 * Solve: recursive.
 * Tips: note which way to route.
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
         * @param node: insert this node into the binary search tree
         * @return: The root of the new binary search tree.
         */
        TreeNode* insertNode(TreeNode* root, TreeNode* node) {
            if (root == NULL) return node;

            if (root->val > node->val) {
                root->left = insertNode(root->left, node);
            } else {
                root->right = insertNode(root->right, node);
            }

            return root;
        }
};
