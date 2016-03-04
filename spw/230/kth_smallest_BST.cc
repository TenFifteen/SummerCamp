/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
/**
 * Problem: Given a binary search tree, write a function
 *          kthSmallest to find the kth smallest element in it.
 * Solve: inorder traverse.
 * Tips: we can also count each subtree and judge the next
 *       call go into.
 */
class Solution {
    public:
        int result;
        int i;
        void sub(TreeNode * root, int k) {
            if (root == NULL || i == k) return;
            sub(root->left, k);
            if (++i == k) {
                result = root->val;
                return;

            }
            sub(root->right, k);

        }

        int kthSmallest(TreeNode* root, int k) {
            i = result = 0;
            sub(root, k);
            return result;

        }
};
