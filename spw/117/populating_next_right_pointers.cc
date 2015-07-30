/**
 * Problem: the given tree could be any binary tree, 
 *          Populating Next Right Pointers in Each Node
 * Solve: dfs, in each invocation, we first connect the chilren
 *        then connect the neighbor.
 * Tips: we should traverse right subtree first, then the left subtree.
 *       only in this way can we obtain the proper next neighbor.
 */
void connect(TreeLinkNode *root) {
	if (root == NULL) return;

	TreeLinkNode *next = NULL;
	TreeLinkNode *temp = root;
	while (temp->next) {
		temp = temp->next;
		if (temp->left || temp->right) {
			next = temp->left ? temp->left : temp->right;
			break;
		}
	}

	if (root->left && root->right) {
		root->left->next = root->right;
		root->right->next = next;
	} else if (root->left){
		root->left->next = next;
	} else if (root->right) {
		root->right->next = next;
	}

	connect(root->right);
	connect(root->left);
}
