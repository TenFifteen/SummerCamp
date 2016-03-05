
/**
 * Problem: Given a binary tree, find the lowest common ancestor
 *          (LCA) of two given nodes in the tree.
 * Solve: Return the p or q or answer.
 * Tips: no
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    return left && right ? root : left ? left : right;
}
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
        int nfind;
        TreeNode *ans;

    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            nfind = 0;
            ans = NULL;
            sub(root, p, q);

            return ans;
        }

        bool sub(TreeNode *root, TreeNode *p, TreeNode *q) {
            if (root == NULL) return false;
            if (ans != NULL) return true;

            bool l = sub(root->left, p, q);
            bool r = sub(root->right, p, q);

            if (ans != NULL) return true;
            bool now = false;
            if (root == p || root == q) {
                nfind++;
                now = true;
            }

            if (nfind == 2) {
                if (now && l || now && r) {
                    ans = root;
                } else if (l && r) {
                    ans = root;
                }
            }

            return l || r || now;
        }
};

