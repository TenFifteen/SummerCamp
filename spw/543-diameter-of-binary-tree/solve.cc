/**
 * Problem: Given a binary tree, you need to compute the length
 *          of the diameter of the tree. The diameter of a binary
 *          tree is the length of the longest path between any two
 *          nodes in a tree. This path may or may not pass through
 *          the root.
 * Solve: dfs
 * Tips: path not the nodes
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
        int diameterOfBinaryTree(TreeNode* root) {
            int res = 1;
            dfs(res, root);

            return res-1;
        }

        int dfs(int &res, TreeNode* root) {
            if (root == NULL) return 0;

            int left = dfs(res, root->left);
            int right = dfs(res, root->right);

            res = max(res, left+right+1);
            return max(left, right) + 1;
        }
};
