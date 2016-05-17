/**
 * Problem: Given a binary tree, return the inorder traversal of its nodes' values.
 * Solve: go left go! go! go!
 * Tips: the condition
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
     * @return: Inorder in vector which contains node values.
     */
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            stack<TreeNode*> s;
            vector<int> ans;

            while (!s.empty() || root) {
                // handle !root
                while (root) {
                    s.push(root);
                    root = root->left;
                }

                // handle !s.empty()
                TreeNode *tmp = s.top();
                s.pop();
                ans.push_back(tmp->val);

                root = tmp->right;
            }

            return ans;
        }
};
