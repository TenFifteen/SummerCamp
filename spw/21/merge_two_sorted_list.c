
/**
 * Problem: merge two sorted list
 * Solve: use a NULL head pointer
 * Tips: NULL
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head = malloc(sizeof(struct ListNode));

	struct ListNode *temp = head;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			temp->next = l1;
			l1 = l1->next;
		} else {
			temp->next = l2;
			l2 = l2->next;
		}
		temp = temp->next;
	}

	while (l1) {
		temp->next = l1;
		l1 = l1->next;
		temp = temp->next;
	}
	while (l2) {
		temp->next = l2;
		l2 = l2->next;
		temp = temp->next;
	}

	return head->next;
}
