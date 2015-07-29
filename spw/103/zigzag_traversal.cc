#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/**
 ** Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Problem: Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 *          (ie, from left to right, then right to left for the next level and alternate between). 
 * Solve: use two stack
 * Tips: noitce the 
 */
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
	vector<vector<int> > ans;

	if (!root) return ans;

	stack<TreeNode *> qa, qb;
	qa.push(root);

	while (!qa.empty() || !qb.empty()) {
		vector<int> levela;
		while (!qa.empty()) {
			TreeNode *now = qa.top();
			qa.pop();

			levela.push_back(now->val);

			// warning!! don't add !
			if (now->left) qb.push(now->left);
			if (now->right) qb.push(now->right);
		}
		if (!levela.empty()) ans.push_back(levela);

		vector<int> levelb;
		while (!qb.empty()) {
			TreeNode *now = qb.top();
			qb.pop();

			levelb.push_back(now->val);

			// notice the order
			if (now->right) qa.push(now->right);
			if (now->left) qa.push(now->left);
		}
		if (!levelb.empty()) ans.push_back(levelb);
	}

	return ans;
}

int main()
{
	TreeNode *root = new TreeNode(0);
	root->left = NULL;
	root->right= NULL;
	vector<vector<int> > ans = zigzagLevelOrder(root);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " "; 
		}
		cout << endl;
	}

	return 0;
}
