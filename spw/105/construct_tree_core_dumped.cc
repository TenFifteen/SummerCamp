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
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
	int n = preorder.size();
	if (n == 0) return NULL;

	TreeNode* now_root = new TreeNode(preorder[0]);
	int pos;
	for (pos = 0; pos < n; ++pos) {
		if (inorder[pos] == preorder[0]) {
			break;
		}
	}

	// left sub-tree
	if (pos > 0) {
		vector<int> left_preorder(pos);
		vector<int> left_inorder(pos);

		for (int i = 0; i < pos; ++i) {
			left_preorder[i] = preorder[i+1];
			left_inorder[i] = inorder[i];
		}
		now_root->left = buildTree(left_preorder, left_inorder);
	}
	// right sub-tree
	if (pos < preorder.size()-1) {
		vector<int> right_preorder(n-pos-1);
		vector<int> right_inorder(n-pos-1);

		for (int i = pos+1; i < n; ++i) {
			// the index must start from 0!!!
			right_preorder[i-1-pos] = preorder[i];
			right_inorder[i-1-pos] = inorder[i];
		}
		now_root->right = buildTree(right_preorder, right_inorder);
	} 	

	return now_root;
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
