void bfs(vector<int> &ans, queue<TreeNode *> &q) {
	if (q.empty()) return;

	queue<TreeNode *> next;
	ans.push_back(q.back()->val);
	while (!q.empty()) {
		TreeNode *now = q.front();
		q.pop();
		if (now->left) next.push(now->left);
		if (now->right) next.push(now->right);
	}

	bfs(ans, next);
}

void dfs(vector<int> &ans, TreeNode* root, int depth) {
	if (!root) return;

	if (depth == ans.size()) ans.push_back(root->val);
	dfs(ans, root->right, depth+1);
	dfs(ans, root->left, depth+1);
}

/**
 * Problem: given a binary tree, return a vector contains the value from top to the bottom
 *          when you see from the right side of the tree.
 * Solve: bfs or dfs, when dfs, use the sequence: root->right->left. We can also think sth
 *        about see from the left view, see from the bottom (root->right->left and now->left
 *        == NULL && now->right == NULL).
 * Tips: no
 */
vector<int> rightSideView(TreeNode* root) {
	vector<int> ans;
	/*if (root == NULL) return ans;
	 *
	 *queue<TreeNode *> q;
	 *q.push(root);
	 *bfs(ans, q);*/

	dfs(ans, root, 0);
	return ans;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;

        if (root) q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> next;
            while (!q.empty()) {
                TreeNode *now = q.front();
                q.pop();
                if (q.empty()) ans.push_back(now->val);

                if (now->left) next.push(now->left);
                if (now->right) next.push(now->right);
            }
            q = next;
        }

        return ans;
    }
};
