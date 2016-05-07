/**
 * Problem: Given the root and two nodes in a Binary Tree. Find the
 *          lowest common ancestor(LCA) of the two nodes.
 *          The lowest common ancestor is the node with largest depth
 *          which is the ancestor of both nodes.
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
        /**
         * @param root: The root of the binary search tree.
         * @param A and B: two nodes in a Binary.
         * @return: Return the least common ancestor(LCA) of the two nodes.
         */
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
            if (root == NULL) return NULL;

            if (root == A || root == B) return root;

            TreeNode *left = lowestCommonAncestor(root->left, A, B);
            TreeNode *right = lowestCommonAncestor(root->right, A, B);

            return left && right ? root : left ? left : right;
        }
};
