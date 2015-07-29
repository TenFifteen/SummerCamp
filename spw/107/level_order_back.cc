void sub(queue<TreeNode *> &q, vector<vector<int> > &ans) {
	queue<TreeNode *> next;
	vector<int> level;
	while (!q.empty()) {
		TreeNode *now = q.front();
		q.pop();

		level.push_back(now->val);
		if (now->left) next.push(now->left);
		if (now->right) next.push(now->right);
	}

	ans.insert(ans.begin(), level);

	if (!next.empty()) {
		sub(next, ans);
	}
}

/**
 * Problem: Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 *          (ie, from left to right, level by level from leaf to root).
 * Solve: recursive, reference to Benchao's code
 * Tips: none
 */
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int> > ans;
	if (root == NULL) return ans;

	queue<TreeNode *> q;
	q.push(root);
	sub(q, ans);
	return ans;
}
