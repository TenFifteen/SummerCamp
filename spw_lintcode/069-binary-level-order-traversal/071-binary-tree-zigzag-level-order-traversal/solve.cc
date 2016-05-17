/**
 * Problem: Given a binary tree, return the zigzag level order traversal of
 *          its nodes' values. (ie, from left to right, then right to left
 *          for the next level and alternate between).
 * Solve: stack + inverse order of push children of each node every level.
 * Tips: convert flag each time.
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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
            stack<TreeNode *> q;

            vector<vector<int>> ans;
            vector<int> level;

            if (root) q.push(root);
            bool flag = true;
            while (!q.empty()) {
                stack<TreeNode *> next;
                while (!q.empty()) {
                    TreeNode *now = q.top();
                    q.pop();

                    level.push_back(now->val);

                    if (flag) {
                        if (now->left) next.push(now->left);
                        if (now->right) next.push(now->right);
                    } else {
                        if (now->right) next.push(now->right);
                        if (now->left) next.push(now->left);
                    }
                }

                q = next;
                ans.push_back(level);
                level.clear();
                flag = !flag;
            }

            return ans;
        }
};
