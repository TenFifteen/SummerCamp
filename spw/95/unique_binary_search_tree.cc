#include <cstdio>
#include <vector>

using namespace std;
/**
 ** Definition for a binary tree node.
 **/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* root = NULL;
void dfs(vector<TreeNode*> &ans, TreeNode* &now_root, int left, int right, int n) {
	if (left > right) {
		now_root = NULL;
		return;
	}

	for (int i = left; i <= right; ++i) {
		now_root = new TreeNode(i);
		dfs(ans, now_root->left, left, i-1, n);
		dfs(ans, now_root->right, i+1, right, n);
		if (left == n && right == n) ans.push_back(root);
	}
}

vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> ans;
	if (n == 0) {
		TreeNode* empty = NULL;
		ans.push_back(empty);
		return ans;
	}

	dfs(ans, root, 1, n, n);
}
int main()
{
	generateTrees(2);
	return 0;
}
