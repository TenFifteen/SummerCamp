/**
 * Problem: Given a binary tree and a sum, find all root-to-leaf 
 *          paths where each path's sum equals the given sum.
 * Solve: dfs + path
 * Tips: if we pass variable 'path' by reference, we should restore
 *       it before we leave this invoking.
 */
void dfs(TreeNode *root, int total, int sum, vector<vector<int> > &ans, vector<int> &path) {
	total += root->val;
	path.push_back(root->val);
	if (root->left == NULL && root->right == NULL) {
		if (total == sum) {
			ans.push_back(path);
			// warn!!
			path.pop_back();
			return;
		}
	}

	if (root->left) dfs(root->left, total, sum, ans, path);
	if (root->right) dfs(root->right, total, sum, ans, path);
	// warn!!
	path.pop_back();
} 

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int> >  ans;
	if (root == NULL) return ans;

	vector<int> path;
	dfs(root, 0, sum, ans, path);
	return ans;
}
