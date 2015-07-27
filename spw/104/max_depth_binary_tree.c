/**
 * Problem: Given a binary tree, find its maximum depth. The maximum depth is the number of 
 *          nodes along the longest path from the root node down to the farthest leaf node.
 * Solve: recusive
 * Tips: add 1
 */
int maxDepth(TreeNode* root) {
	if (!root) return 0;

	int leftHeight = 1 + maxDepth(root->left);
	int rightHeight = 1 + maxDepth(root->right);

	return leftHeight > rightHeight ? leftHeight : rightHeight;
}
