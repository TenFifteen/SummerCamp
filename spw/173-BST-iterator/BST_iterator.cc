#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 ** Definition for binary tree
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

stack<TreeNode *> nodes;
TreeNode* now = NULL;
/**
 * Problem: Implement an iterator over a binary search tree (BST).
 *          Your iterator will be initialized with the root node of a BST.
 * Sovle: divide the traversal of inorder.
 * Tips: the outer while loop must be removed
 */
void BSTIterator(TreeNode *root) {
	now = root;
	while (now) {
		nodes.push(now);
		now = now->left;
	}
	if (!nodes.empty()) {
		now = nodes.top();
		nodes.pop();
	}
}

/** @return whether we have a next smallest number */
bool hasNext() {
	return now || !nodes.empty();
}

/** @return the next smallest number */
int next() {
	int val = now->val;
	now = now->right;
	while (now) {
		nodes.push(now);
		now = now->left;
	}
	if (!nodes.empty()) {
		now = nodes.top();
		nodes.pop();
	}
	return val;
}

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *right = new TreeNode(2);
	root->right = right;
	BSTIterator(root);
	while (hasNext()) cout << next() << endl;

	return 0;
}


class BSTIterator {
    stack<TreeNode *> nodes;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            nodes.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* it = nodes.top();
        nodes.pop();
        int ans = it->val;
        it = it->right;
        while (it) {
            nodes.push(it);
            it = it->left;
        }

        return ans;
    }
};
