/**
 * Problem: Given two values k1 and k2 (where k1 < k2) and a root pointer to
 *          a Binary Search Tree. Find all the keys of tree in range k1 to
 *          k2. i.e. print all x such that k1<=x<=k2 and x is a key of given
 *          BST. Return all the keys in ascending order.
 * Solve: inorder traversal and pruning
 * Tips: no
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
    public:
        /**
         * @param root: The root of the binary search tree.
         * @param k1 and k2: range k1 to k2.
         * @return: Return all keys that k1<=key<=k2 in ascending order.
         */
        vector<int> searchRange(TreeNode* root, int k1, int k2) {
            vector<int> ans;

            sub(ans, root, k1, k2);
            return ans;
        }

        void sub(vector<int> &ans, TreeNode *root, int k1, int k2) {
            if (root == NULL) return;

            if (k1 <= root->val)
                sub(ans, root->left, k1, k2);

            if (root->val >= k1 && root->val <= k2) ans.push_back(root->val);

            if (root->val <= k2)
                sub(ans, root->right, k1, k2);
        }
};
