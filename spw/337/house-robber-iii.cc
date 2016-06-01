/**
 * Problem: The thief has found himself a new place for his thievery again. There
 *          is only one entrance to this area, called the "root." Besides the root,
 *          each house has one and only one parent house. After a tour, the smart
 *          thief realized that "all houses in this place forms a binary tree". It
 *          will automatically contact the police if two directly-linked houses were
 *          broken into on the same night.
 * Solve: map + dfs
 * Tips: see comments below.
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
    private:
        unordered_map<TreeNode*, pair<int, int>> nodeVal;
        void dfs(TreeNode *root) {
            if (root == NULL) return;

            int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
            if (root->left) {
                dfs(root->left);
                l1 = nodeVal[root->left].first;
                l2 = nodeVal[root->left].second;
            }

            if (root->right) {
                dfs(root->right);
                r1 = nodeVal[root->right].first;
                r2 = nodeVal[root->right].second;
            }

            nodeVal[root].first = root->val + l2 + r2;
            nodeVal[root].second = l1 + r1;

            // the first which includes the root should use the maximum.
            nodeVal[root].first = max(nodeVal[root].first, nodeVal[root].second);
        }
    public:
        int rob(TreeNode* root) {
            if (root == NULL) return 0;

            nodeVal.clear();
            dfs(root);

            return nodeVal[root].first;
        }
};
