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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            TreeNode *now = q.front();
            swap(now->left, now->right);
            q.pop();

            if (now->left) q.push(now->left);
            if (now->right) q.push(now->right);
        }

        return root;
    }
};
