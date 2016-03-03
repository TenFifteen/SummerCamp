/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Problem: Invert a binary tree.
 * Solve: Recursive.
 * Tips: save children ahead.
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        TreeNode *l = root->left;
        TreeNode *r = root->right;

        root->left = invertTree(r);
        root->right = invertTree(l);

        return root;
    }
};
