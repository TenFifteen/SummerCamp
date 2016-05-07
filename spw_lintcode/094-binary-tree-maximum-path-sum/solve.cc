/**
 * Problem: Given a binary tree, find the maximum path sum.
 *          The path may start and end at any node in the tree.
 * Solve: use a sub procedure to get the max path sum from the root
 *        to leaf. And update the maximum path by pass.
 * Tips: we need not use dp, because every node has only been calculate
 *       once from bottom to top.
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
         * @return: An integer
         */
        int maxPathSum(TreeNode *root) {
            if (root == NULL) return 0;

            int ans = root->val;
            rootPathSum(ans, root);

            return ans;
        }

        int rootPathSum(int &ans, TreeNode *root) {
            if (root == NULL) return 0;

            int l = rootPathSum(ans, root->left);
            int r = rootPathSum(ans, root->right);

            if (l < 0) l = 0;
            if (r < 0) r = 0;

            ans = max(ans, l+r+root->val);

            return max(l, r) + root->val;
        }
};
