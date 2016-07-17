#include <cstdio>
#include <vector>
#include <stack>

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

void traverse(vector<int> &ans, TreeNode *root) {
	if (!root) return;

	traverse(ans, root->left);
	ans.push_back(root->val);
	traverse(ans, root->right);
}

/**
 * Problem: binary tree inorder traversal
 * Solve: recursion
 * Tips: see below
 */
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	traverse(ans, root);
	return ans;
}

vector<int> non_recur(vector<int> &ans, TreeNode* root) {
	stack<TreeNode *> nodes;

	TreeNode* node = root;
	// the node is not in the stack at first
	while (node || !nodes.empty()) {
		while (node) {
			nodes.push(node);
			node = node->left;
		}
		node = nodes.top();
		nodes.pop();
		// visit when pop it
		ans.push_back(node->val);

		node = node->right;
	}
	return ans;
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;

        vector<int> ans;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }

            TreeNode *now = s.top();
            s.pop();
            ans.push_back(now->val);
            root = now->right;
        }

        return ans;
    }
};
