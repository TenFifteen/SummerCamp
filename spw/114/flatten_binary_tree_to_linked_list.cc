
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
