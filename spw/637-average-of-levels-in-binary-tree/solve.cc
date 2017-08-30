/**
 * Problem:  Given a non-empty binary tree, return the average value of
 *           the nodes on each level in the form of an array.
 * Solve: ues queue to traversal in level
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
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> res;
            queue<TreeNode*> level;

            if (root) level.push(root);
            while (!level.empty()) {
                queue<TreeNode*> next;
                long long sum = 0;
                int cnt = level.size();

                while (!level.empty()) {
                    TreeNode *now = level.front();
                    level.pop();

                    sum += now->val;
                    if (now->left) next.push(now->left);
                    if (now->right) next.push(now->right);
                }

                level = next;
                res.push_back((double)sum / cnt);
            }


            return res;
        }
};
