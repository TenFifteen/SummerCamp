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
/**
 * Problem: Given a sorted (increasing order) array,
 *          Convert it to create a binary tree with minimal height.
 * Solve: recursive
 * Tips: no
 */
class Solution {
    TreeNode *sub(vector<int> &A, int l, int r) {
        if (l > r) return NULL;

        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(A[mid]);

        root->left = sub(A, l, mid-1);
        root->right = sub(A, mid+1, r);
        return root;
    }
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        return sub(A, 0, A.size()-1);
    }
};
