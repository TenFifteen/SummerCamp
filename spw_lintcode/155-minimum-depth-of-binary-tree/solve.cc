/**
 * Problem: Given a binary tree, find its minimum depth.
 *          The minimum depth is the number of nodes along
 *          the shortest path from the root node down to the nearest leaf node.
 * Solve: dfs+global variable.
 * Tips: the path must end with the leaf!! not null
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
        int minDepth(TreeNode *root) {
            if (root == NULL) return 0;
            ans = INT_MAX;
            dfs(root, 0);

            return ans;
        }

        int ans;
        void dfs(TreeNode *root, int pre) {
            if (root == NULL) return;

            ++pre;
            if (root->left == NULL && root->right == NULL) {
                ans = min(ans, pre);
            }

            dfs(root->left, pre);
            dfs(root->right, pre);
        }


};
