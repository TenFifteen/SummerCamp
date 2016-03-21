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
/**
 * Problem: Flatten a binary tree to a fake "linked list" in pre-order traversal.
 *          Here we use the right pointer in TreeNode as the next pointer in ListNode.
 * Solve: preorder traversal.
 * Tips: Don't forget to assign the left child pointer to null
 */
class Solution {
    private:
        TreeNode *preTraversal(TreeNode *root){
            if (root == NULL) return NULL;

            TreeNode *left = preTraversal(root->left);
            TreeNode *right = preTraversal(root->right);

            // Use the last node
            TreeNode *it = root;
            if (left) {
                it->right = left;
                while (it->right) {
                    it = it->right;
                }
            }

            if (right) {
                it->right = right;
            }

            root->left = NULL;
            return root;
        }
    public:
        /**
         * @param root: a TreeNode, the root of the binary tree
         * @return: nothing
         */
        void flatten(TreeNode *root) {
            root = preTraversal(root);
        }
};
