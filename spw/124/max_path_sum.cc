
int maxPathSumFromRoot(TreeNode *root, int &max_sum) {
	if (root == NULL) return 0;

	int left = maxPathSumFromRoot(root->left, max_sum);
	int right = maxPathSumFromRoot(root->right, max_sum);

	if (left < 0) left = 0;
	if (right < 0) right = 0;

	max_sum = max(max_sum, left+right+root->val);

	return max(left, right) + root->val;
}

/**
 * Problem: Given a binary tree, find the maximum path sum.
 *          The path may start and end at any node in the tree.
 * Solve: find the maximum sum of path from root of each binary tree's node
 *        then combine left and right to see if it is greater than the before 
 * Tips: 1. notice if the subtrees' result will be less than 0
 *       2. in every node we have made the judgement, that is, we have considered 
 *          all conditions in every node: a) the path in the node's left subtrees(means the right sum < 0)
 *          b) the path in left node's right subtrees c) pass the node
 */
int maxPathSum(TreeNode* root) {
	if (!root) return 0;
	
	int max_sum = (0x1 << 31);
	maxPathSum(root, max_sum);
	return max_sum;
}
