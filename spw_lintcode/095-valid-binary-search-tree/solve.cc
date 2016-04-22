/**
 * Problem: Given a binary tree, determine if it is a valid binary search tree (BST).
 * Solve: in order traversal, and keep the previous tree node pointer.
 * Tips: 1. handle border first
 *       2. handle left --> just call itself with left child tree as parameter.
 *       3. handle now judge relation between previous and now node. and update prev node.
 *       4. handle the right subtree
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
         * @return: True if the binary tree is BST, or false
         */
        bool isValidBST(TreeNode *root) {
            TreeNode *prev = NULL;

            return sub(root, prev);
        }

        bool sub(TreeNode *root, TreeNode* &prev) {
            if (root == NULL) return true;

            if (!sub(root->left, prev)) return false;
            if (prev != NULL && prev->val >= root->val) return false;
            prev = root;
            return sub(root->right, prev);
        }
};
