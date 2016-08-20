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
 * Problem: Given a binary search tree, find the lowest ancestor of two given
 *          nodes in the BST.
 * Solve: Use the ordering of BST to recursive.
 * Tips: no
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        // it's not nessary
        //if (p == q) return p;

        if (p->val > q->val) {
            TreeNode *tmp = q;
            q = p;
            p = tmp;
        }

        // must have equal for the case root will be either p or q
        if (p->val <= root->val && root->val <= q->val) return root;

        if (q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val) return lowestCommonAncestor(root->right, p, q);
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        return left && right ? root : left ? left : right;
    }
};
