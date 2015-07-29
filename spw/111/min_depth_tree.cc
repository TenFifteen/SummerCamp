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
