/**
 * Problem: Given inorder and postorder traversal of a tree, construct the binary tree.
 * Solve: use two start point and a length.
 * Tips: see comments below.
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
    public:
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            return build(inorder, 0, postorder, 0, inorder.size());
        }

        TreeNode *build(vector<int> &inorder, int l1, vector<int> &postorder, int l2, int len) {
            if (len == 0) return NULL;

            int r = postorder[l2+len-1];
            int i = 0;
            // i as the length of left subtree
            while (i < len && inorder[i+l1] != r) ++i;

            TreeNode *root = new TreeNode(r);
            root->left = build(inorder, l1, postorder, l2, i);
            root->right = build(inorder, l1+i+1, postorder, l2+i, len-i-1);

            return root;
        }
};
