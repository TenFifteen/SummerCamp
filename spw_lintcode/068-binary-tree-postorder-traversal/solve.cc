/**
 * Problem: Given a binary tree, return the postorder traversal of its nodes' values.
 * Solve: root->right->left && reverse
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
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> ans;

            stack<TreeNode*> s;
            if (root) s.push(root);
            while (!s.empty()) {
                TreeNode *now = s.top();
                s.pop();
                ans.push_back(now->val);

                if (now->left) s.push(now->left);
                if (now->right) s.push(now->right);
            }

            reverse(ans.begin(), ans.end());

            return ans;
        }
};
