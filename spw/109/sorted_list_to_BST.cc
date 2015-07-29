ListNode *list;

// n is the count, we should remeber it, then 
// when we call, we should pass the proper paramters
TreeNode* inorder(int n) {
	if (n <= 0) return NULL;

	int mid = n/2;
	TreeNode *now_root = new TreeNode(0);

	// n/2
	now_root->left = inorder(n/2);
	// notice the order of the following two sentences
	// For example: n = 1, list = head;
	now_root->val = list->val; 
	list = list->next;
	now_root->right = inorder(n - 1 - n/2);

	return now_root;
}

/**
 * Problem: Given a singly linked list where elements are sorted in ascending order, 
 *          convert it to a height balanced BST.
 * Solve: copy from the discuss board. 
 * Tips: we can think about this problem like this: the list is the inorder traversal 
 *       of the binary tree, traversing the tree in inorder is equal to retrieving the 
 *       linked list from left to right.
 */
TreeNode* sortedListToBST(ListNode* head) {
	ListNode *node = head;
	int count = 0;
	while (node) {
		count++;
		node = node->next;
	}
	if (count == 0) return NULL;

	this->list = head;
	return inorder(count);
}
