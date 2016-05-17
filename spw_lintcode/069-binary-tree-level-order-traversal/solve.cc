/**
 * Problem: Given a binary tree, return the bottom-up level order traversal
 *          of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * Solve: just do it and reverse in the end;
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
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
    public:
        vector<vector<int>> levelOrderBottom(TreeNode *root) {
            queue<TreeNode *> q;

            vector<vector<int>> ans;
            vector<int> level;

            if (root) q.push(root);
            bool flag = true;
            while (!q.empty()) {
                queue<TreeNode *> next;
                while (!q.empty()) {
                    TreeNode *now = q.front();
                    q.pop();

                    level.push_back(now->val);

                    if (now->left) next.push(now->left);
                    if (now->right) next.push(now->right);
                }

                q = next;
                ans.push_back(level);
                level.clear();
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
};
