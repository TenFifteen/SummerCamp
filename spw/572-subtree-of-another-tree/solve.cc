/**
 * Problem: Given two non-empty binary trees s and t, check whether tree t has
 *          exactly the same structure and node values with a subtree of s. A
 *          subtree of s is a tree consists of a node in s and all of this node's
 *          descendants. The tree s could also be considered as a subtree of itself.
 * Solve: recursive + stack
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
        bool isSubtree(TreeNode* s, TreeNode* t) {
            stack<TreeNode*> nodes;
            while (s || !nodes.empty()) {
                if (s == NULL) {
                    TreeNode* node = nodes.top();
                    s = node->right;
                    nodes.pop();

                    if (isSame(node, t)) return true;
                } else {
                    nodes.push(s);
                    s = s->left;
                }
            }

            return false;
        }

        bool isSame(TreeNode* root1, TreeNode* root2) {
            if (root1 == NULL || root2 == NULL)
                return root1 == root2;

            return root1->val == root2->val && isSame(root1->left, root2->left)
                && isSame(root1->right, root2->right);
        }
};
