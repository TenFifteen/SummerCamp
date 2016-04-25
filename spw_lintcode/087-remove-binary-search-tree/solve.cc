/**
 * Problem: Given a root of Binary Search Tree with unique value for each node.
 *          Remove the node with given value. If there is no such a node with
 *          given value in the binary search tree, do nothing. You should keep
 *          the tree still a binary search tree after removal.
 * Solve: 1. use value to route left right or now root node.
 *        2. if is now date node, then handle separately by the count of children
 *           of the node.
 *        3. if the node has less than one children, return the other child directly.
 *           Otherwise, replace with the next number(must in the left subtree), and
 *           remove the next number of the left tree.
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
        TreeNode* getLeftMost(TreeNode *root) {
            while (root->left) {
                root = root->left;
            }

            return root;
        }
        /**
         * @param root: The root of the binary search tree.
         * @param value: Remove the node with given value.
         * @return: The root of the binary search tree after removal.
         */
        TreeNode* removeNode(TreeNode* root, int value) {
            if (root == NULL) return NULL;

            if (value > root->val) {
                root->right = removeNode(root->right, value);
            } else if (value < root->val) {
                root->left = removeNode(root->left, value);
            } else {
                if (root->left && root->right) {
                    TreeNode *tmp = getLeftMost(root);
                    root->val = tmp->val;

                    root->left = removeNode(root->left, tmp->val);
                } else {
                    if (root->left == NULL) {
                        root = root->right;
                    } else if (root->right == NULL) {
                        root = root->left;
                    }
                }
            }

            return root;
        }
};
