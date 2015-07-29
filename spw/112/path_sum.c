/**
 ** Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool find = false;
void dfs(struct TreeNode *root, int total, int sum) {
	total += root->val;
	if (root->left == NULL && root->right == NULL) {
		if (total == sum) {
			find = true;
			return;
		}
	}

	if (root->left) dfs(root->left, total, sum);
	if (root->right) dfs(root->right, total, sum);
	if (find) return;
} 

/**
 * Problem: Given a binary tree and a sum, determine if the tree has a 
 *          root-to-leaf path such that adding up all the values along 
 *          the path equals the given sum.
 * Solve: dfs + global variables
 * Tips: no
 */
bool hasPathSum(struct TreeNode* root, int sum) {
	if (root == NULL) return false;

	find = false;
	dfs(root, 0, sum);
	return find;
}
