void dfs(vector<int> &ans, TreeNode* root) {
	ans.push_back(root->val);
	if (root->left) dfs(ans, root->left);
	if (root->right) dfs(ans, root->right);
}
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ans;
	if (root == NULL) return ans;
	dfs(ans, root);
}

/**
 * Problem: given an binary tree, return its preorder traversal of its nodes' values.
 * Solve: simple idea. 
 * Tips: none
 */
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ans;
	if (root == NULL) return ans;

	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty()) {
		TreeNode* now = s.top();
		s.pop();

		ans.push_back(now->val);
		if (now->right) s.push(now->right);
		if (now->left) s.push(now->left);
	}

	return ans;
}
