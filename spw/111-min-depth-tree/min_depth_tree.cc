/**
 * Problem: Given a binary tree, find its minimum depth. The minimum depth is
 *          the number of nodes along the shortest path
 *          from the root node down to the nearest leaf node.
 * Solve: recursive
 * Tips: the leaf mean nodes whose two children are all NULL.
 *       Then if one of the children is NULL, the depth(root) = depth(child not NULL) + 1
 */
int minDepth(TreeNode* root) {
    if (root == NULL) return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);


    if (left == 0) {
        return right + 1;
    }

    if (right == 0) {
        return left + 1;
    }

    return right < left ? right + 1 : left + 1;
}

class Solution {
    public:
        int minDepth(TreeNode* root) {
            if (root == NULL) return 0;

            if (root->left == NULL && root->right == NULL) return 1;

            int left = root->left ? minDepth(root->left) : INT_MAX;
            int right = root->right ? minDepth(root->right) : INT_MAX;

            return min(left, right) + 1;

        }

};
