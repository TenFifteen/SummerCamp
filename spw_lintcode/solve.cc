/**
 * Problem: Given a binary tree, return all root-to-leaf paths.
 * Solve: dfs
 * Tips: The time to put a path to the result vector: in the leaf node
 *       instead of the null node.
 *       handle the "->" carefully.
 *       more details see comments below.
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
    private:
        void dfs(vector<string> &ans, string prefix, TreeNode* root) {
            if (root == NULL) return;

            if (prefix != "") prefix += "->";
            prefix += to_string(root->val);

            if (root->left == NULL && root->right == NULL) {
                ans.push_back(prefix);
                return;
            }

            dfs(ans, prefix, root->left);
            dfs(ans, prefix, root->right);
        }
    public:
        /**
         * @param root the root of the binary tree
         * @return all root-to-leaf paths
         */
        vector<string> binaryTreePaths(TreeNode* root) {
            // Write your code here
            vector<string> ans;
            dfs(ans, "", root);

            return ans;
        }
};
