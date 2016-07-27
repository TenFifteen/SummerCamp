#include <iostream>
#include <queue>
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
 * Problem: Given a binary tree, return the level order traversal of its nodes' values.
 *          (ie, from left to right, level by level).
 * Solve: use two queues, bfs
 * Tips: noitce the !
 */
vector<vector<int> > levelOrder(TreeNode* root) {
	vector<vector<int> > ans;

	if (!root) return ans;

	queue<TreeNode *> qa, qb;
	qa.push(root);

	while (!qa.empty() || !qb.empty()) {
		vector<int> levela;
		while (!qa.empty()) {
			TreeNode *now = qa.front();
			qa.pop();

			levela.push_back(now->val);

			// warning!! don't add !
			if (now->left) qb.push(now->left);
			if (now->right) qb.push(now->right);
		}
		if (!levela.empty()) ans.push_back(levela);

		vector<int> levelb;
		while (!qb.empty()) {
			TreeNode *now = qb.front();
			qb.pop();

			levelb.push_back(now->val);

			if (now->left) qa.push(now->left);
			if (now->right) qa.push(now->right);
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
	vector<vector<int> > ans = levelOrder(root);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty()) {
            queue<TreeNode *> next;
            vector<int> level;

            while (!q.empty()) {
                TreeNode *now = q.front();
                q.pop();

                level.push_back(now->val);
                if (now->left) next.push(now->left);
                if (now->right) next.push(now->right);
            }

            q = next;
            ans.push_back(level);
        }

        return ans;
    }
};
