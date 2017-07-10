/**
 * Problem: Given a binary tree, return the tilt of the whole tree.
 *
 *          The tilt of a tree node is defined as the absolute difference
 *          between the sum of all left subtree node values and the sum of
 *          all right subtree node values. Null node has tilt 0.
 *
 *          The tilt of the whole tree is defined as the sum of all nodes' tilt.
 * Solve: dfs
 * Tips: no
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
        int findTilt(TreeNode* root) {
            int res = 0;
            dfs(root, res);
            return res;
        }

        int dfs(TreeNode* root, int &res) {
            if (root == NULL) return 0;

            int left = dfs(root->left, res);
            int right = dfs(root->right, res);

            res += abs(left-right);
            return left+right+root->val;
        }
};
