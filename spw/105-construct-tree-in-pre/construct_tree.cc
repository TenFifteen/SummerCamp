#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* dfs(vector<int> &preorder, int l_pre, int r_pre, vector<int> &inorder, int l_in, int r_in)
{
	if (l_pre > r_pre) return NULL;

	int pos = 0;
	while (inorder[l_in+pos] != preorder[l_pre])	pos++;

	TreeNode* now_root = new TreeNode(preorder[l_pre]);
	now_root->left = dfs(preorder, l_pre+1, l_pre+pos, inorder, l_in, l_in+pos-1);
	now_root->right = dfs(preorder, l_pre+pos+1, r_pre, inorder, l_in+pos+1, r_in);

	return now_root;
}

/**
 * Problem: Given preorder and inorder traversal of a tree, construct the binary tree.
 * Solve: dfs
 * Tips: needn't construct now vector, just pass the position as parameters, because
 *       the data we need to pass is continuous
 */
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
	int n = preorder.size();
	if (n == 0) return NULL;

	return dfs(preorder, 0, n-1, inorder, 0, n-1);
}

int main()
{

	int n;
	while (cin >> n) {
		vector<int> preorder(n);
		vector<int> inorder(n);

		int temp;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &temp);
			preorder[i] = temp;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &temp);
			inorder[i] = temp;
		}

		TreeNode *root = buildTree(preorder, inorder);
	}

	return 0;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return sub(preorder, inorder, 0, 0, preorder.size());
    }

    TreeNode *sub(vector<int> &pre, vector<int> &in, int x, int y, int len) {
        if (len <= 0) return NULL;

        TreeNode *root = new TreeNode(pre[x]);
        int s = y;
        while (in[s] != root->val) ++s;

        int llen = s - y, rlen = len - llen - 1;

        root->left = sub(pre, in, x+1, y, llen);
        root->right = sub(pre, in, x+1+llen, y+1+llen, rlen);

        return root;
    }
};
