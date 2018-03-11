
TreeNode* prev = NULL;

/**
 * Problem: Given a binary tree, flatten it to a linked list in-place.
 * Solve: copy from the discuss board
 * Tips: prev
 */
// the prev was updated in any nod
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

void flatten(TreeNode* root) {
    stack<TreeNode*> s;
    if (root) s.push(root);

    TreeNode dummy(0);
    TreeNode* tail = &dummy;

    while (!s.empty()) {
        TreeNode* now = s.top();
        s.pop();

        if(now->right) s.push(now->right);
        if(now->left) s.push(now->left);

        tail->right = now;
        tail->left = NULL;
        tail = tail->right;
    }
}
