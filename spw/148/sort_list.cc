/**
 * Problem: sort a linked list in O(nlgn) time using constant space complexity.
 * Solve: merge sort.
 * Tips: divide it into modules, and make it clearly
 */
ListNode* merge(ListNode* A, ListNode* B) {
	ListNode* head = new ListNode(0);
	ListNode* tail = head;

	ListNode *it1 = A, *it2 = B;
	while (it1 && it2) {
		ListNode *now = NULL;
		if (it1->val < it2->val) {
			now = it1;
			it1 = it1->next;
		} else {
			now = it2;
			it2 = it2->next;
		}
		tail->next = now;
		tail = now;
		tail->next = NULL;
	}

	while (it1) {
		ListNode *now = it1;
		it1 = it1->next;

		tail->next = now;
		tail = now;
		tail->next = NULL;
	}

	while (it2) {
		ListNode *now = it2;
		it2 = it2->next;

		tail->next = now;
		tail = now;
		tail->next = NULL;
	}

	tail = head;
	head = head->next;
	delete tail;

	return head;
}

ListNode* mysort(ListNode* head, int count) {
	if (count < 2) return head;

	int half = count / 2 - 1;
	ListNode *head1 = head;;
	while (half--) {
		head1 = head1->next; 
	}
	ListNode *tail = head1;
	head1 = head1->next;
	tail->next = NULL;

	head = mysort(head, count/2);
	head1 = mysort(head1, count-count/2);

	return merge(head, head1);
}

ListNode* sortList(ListNode* head) {
	int count = 0;
	ListNode *it = head;
	while (it) {
		it = it->next;
		++count;
	}

	return mysort(head, count);
}
