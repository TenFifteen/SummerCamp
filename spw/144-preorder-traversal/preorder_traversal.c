/**
 * Problem: Given a binary tree, return the preorder traversal of its nodes' values.
 * Solve: use the stack s to save the path when we dive into the left branches.
 * Tips: no
 */
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            stack<TreeNode *> s;
            vector<int> ans;

            while (root || !s.empty()) {
                if (root == NULL) {
                    // reach the leaf, pop one from the path, and visit its right
                    // branches
                    root = s.top();
                    s.pop();
                    root = root->right;
                } else {
                    // We visit the node only the root is not null
                    s.push(root);
                    ans.push_back(root->val);
                    root = root->left;
                }
            }

            return ans;
        }
};
