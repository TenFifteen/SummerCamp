void flatten(TreeNode* root) {
    while (root) {
        if (root->left) {
            TreeNode* t = root->left;
            while (t->right) {
                t = t->right;
            }
            t->right = root->right;

            root->right = root->left;
            root->left = NULL;
        }

        root = root->right;
    }
}
