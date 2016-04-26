/**
 * Problem: Given preorder and inorder traversal of a tree, construct the binary tree.
 * Solve: just do it.
 * Tips: find root in the inorder traversal, with i which will become length of left
 *       subtree.
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
    public:
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            return build(preorder, 0, inorder, 0, preorder.size());
        }

        TreeNode *build(vector<int> &preorder, int l1, vector<int> &inorder, int l2, int len) {
            if (len == 0) return NULL;

            int r = preorder[l1];
            int i = 0;
            while (i < len && inorder[i+l2] != r) ++i;

            TreeNode *root = new TreeNode(r);

            root->left = build(preorder, l1+1, inorder, l2, i);
            root->right = build(preorder, l1+i+1, inorder, l2+i+1, len-i-1);

            return root;
        }
};
