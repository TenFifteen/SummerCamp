#include <cstdio>
#include <queue>

using namespace std;

/**
 ** Definition for binary tree with next pointer.
 **/
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void sub(queue<TreeLinkNode *> &q) {
	if (q.empty()) return;

	TreeLinkNode *prev = NULL;
	queue<TreeLinkNode *> next;
	while (!q.empty()) {
		TreeLinkNode *now_root = q.front();
		q.pop();

		// warn: first in first out
		if (prev == NULL) {
			prev = now_root;
		} else {
			prev->next = now_root;
			prev = now_root;
		}

		if (now_root->left) next.push(now_root->left);
		if (now_root->right) next.push(now_root->right);
	}

	sub(next);
}

/**
 * Problem: Populate each next pointer to point to its next right node.
 *          If there is no next right node, the next pointer should be set to NULL.
 * Solve: traverse hierachically and populate each node to its next
 * Tips: pay attention to the sequence of the elements in queue
 */
void connect(TreeLinkNode *root) {
	if (root == NULL) return;

	queue<TreeLinkNode *> q;
	q.push(root);
	sub(q);
}

int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	TreeLinkNode *left = new TreeLinkNode(2);
	TreeLinkNode *right = new TreeLinkNode(3);
	root->left = left; root->right = right;
	connect(root);

	return 0;
}

void connect(TreeLinkNode *root) {
        TreeLinkNode *level = root, *dummy = new TreeLinkNode(0);

        while (level) {
            TreeLinkNode *it = level, *prev = dummy;
            while (it) {
                if (it->left && it->right) {
                    prev->next = it->left;
                    it->left->next = it->right;
                    prev = it->right;
                } else if (it->left) {
                    prev->next = it->left;
                    prev = it->left;
                } else if (it->right) {
                    prev->next = it->right;
                    prev = it->right;
                }

                it = it->next;
            }

            prev->next = NULL;
            level = dummy->next;
        }
    }
