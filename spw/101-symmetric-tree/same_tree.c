/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     struct TreeNode *left;
 **     struct TreeNode *right;
 ** };
 **/

/**
 * Problem: Given two binary trees, write a function to check if they are equal or not.
 * Solve: recurse
 * Tips: the value of node should equal also
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (!p || !q) {
		if (!p && !q) return true;
		return false;
	}

	return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
