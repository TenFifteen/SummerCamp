bool sub(TreeNode *root, int *height)
{
	if (root == NULL) {
		*height = 0;
		return true;
	}


	int left_height = 0, right_height = 0;
	bool left = sub(root->left, &left_height);
	bool right = sub(root->right, &right_height);

	// we should keep in mind what the *height means
	*height = left_height > right_height ? left_height+1 : right_height+1;

	return left && right && fabs(left_height-right_height) <= 1;
}

/**
 * Problem: Given a binary tree, determine if it is height-balanced.
 * Solve: use the pointer as another parameters to hold the height of the
 *        current tree rooted with the first parameters
 * Tips: see above
 */
bool isBalanced(TreeNode* root) {
	int height = 0;
	return  sub(root, &height);
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int len;
        return sub(root, len);
    }

    bool sub(TreeNode* root, int &len) {
        if (root == NULL) {
            len = 0;
            return true;
        }

        int l, r;
        bool left = sub(root->left, l);
        bool right = sub(root->right, r);

        len = max(l, r) + 1;
        if (abs(l-r) < 2 && left && right) {
            return true;
        } else {
            return false;
        }
    }
};
