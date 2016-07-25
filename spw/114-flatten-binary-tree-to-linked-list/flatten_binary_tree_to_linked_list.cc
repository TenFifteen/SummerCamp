
TreeNode* prev = NULL;

/**
 * Problem: Given a binary tree, flatten it to a linked list in-place.
 * Solve: copy from the discuss board
 * Tips: prev
 */
void flatten(TreeNode* root) {
    if (root == NULL) return;

    flatten(root->right);
    flatten(root->left);


    root->left = NULL;
    root->right = prev;
    prev = root;
}

/**
 * My own
 */
TreeNode *inorder(TreeNode *root) {
    if (root == NULL) return NULL;

    TreeNode *left = inorder(root->left);
    TreeNode *right = inorder(root->right);

    root->left = NULL;
    if (left != NULL) {
        root->right = left;

        TreeNode *pre = left;
        while (left) {
            pre = left;
            left = left->right;
        }
        pre->right = right;
        pre->left = NULL;
    } else {
        root->right = right;
    }

    return root;
}

void flatten(TreeNode* root) {
    root = inorder(root);
}

class Solution {
    public:
        void flatten(TreeNode* root) {
            if (root == NULL) return;
            root = back(root);
        }

        TreeNode *back(TreeNode *root) {
            if (root == NULL) return NULL;

            TreeNode *left = back(root->left);
            TreeNode *right = back(root->right);

            if (left == NULL) root->right = right;
            else {
                root->right = left;
                TreeNode *it = left;
                while (it->right) it = it->right;
                it->right = right;
            }

            // set left pointer NULL
        root->left = NULL;
        return root;
    }
};
