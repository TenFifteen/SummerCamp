#include <iostream>

using namespace std;

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
 * Problem: Given a binary tree, return all root-to-leaf paths.
 * Solve: preorder traversal.
 * Tips: The time to save one path.
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;

        string prefix = to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(prefix);
        } else {
            sub(ans, root->left, prefix);
            sub(ans, root->right, prefix);
        }

        return ans;
    }

    void sub(vector<string> &ans, TreeNode *root, string prefix) {
        if (root == NULL) return;

        prefix += ("->" + to_string(root->val));

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(prefix);
            return;
        }

        sub(ans, root->left, prefix);
        sub(ans, root->right, prefix);
    }
};
