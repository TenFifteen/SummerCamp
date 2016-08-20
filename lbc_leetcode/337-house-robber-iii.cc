/*
 * ok
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
private:
    pair<int, int> _rob(TreeNode *root) {
        if (root == NULL) return make_pair(0, 0);
        auto left = _rob(root->left);
        auto right = _rob(root->right);
        return make_pair(max(left.second, left.first) + max(right.second, right.first), left.first + right.first + root->val);
    }

public:
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        auto ret = _rob(root);
        return max(ret.first, ret.second);
    }
};
