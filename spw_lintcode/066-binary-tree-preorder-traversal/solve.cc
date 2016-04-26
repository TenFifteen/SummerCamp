/**
 * Problem: Given a binary tree, return the preorder traversal of its nodes' values.
 * Solve: just let the left children pushed into the stack first.
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
    public:
        /**
         * @param root: The root of binary tree.
         * @return: Preorder in vector which contains node values.
         */
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> ans;
            stack<TreeNode*> s;
            if (root) s.push(root);
            while (!s.empty()) {
                TreeNode *now = s.top();
                s.pop();
                ans.push_back(now->val);

                if (now->right) s.push(now->right);
                if (now->left) s.push(now->left);
            }


            return ans;
        }
};

