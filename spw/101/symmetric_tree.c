/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     struct TreeNode *left;
 **     struct TreeNode *right;
 ** };
 **/

bool leftRightSymmetric(struct TreeNode* left, struct TreeNode* right)
{
	if (!left || !right) {
		return left == right;
	}

	return left->val == right->val && leftRightSymmetric(left->right, right->left) && leftRightSymmetric(left->left, right->right);
}

/**
 * Problem: Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * Solve: recusive: it is symmetric around the center if we see on every node
 *        then we can use recusive
 * Tips: no
 */
bool isSymmetric(struct TreeNode* root) {
	return !root || leftRightSymmetric(root->left, root->right);
}
