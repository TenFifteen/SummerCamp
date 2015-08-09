/**
 * Problem: given an linked list, determine if it has a cycle in it
 * Solve: use two pointers
 * Tips: no
 */
bool hasCycle(struct ListNode *head) {
	struct ListNode *temp1 = head, *temp2 = head;

	while (temp1 && temp2) {
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2) {
			temp2 = temp2->next;
			if (temp2 == temp1) {
				return true;
			}
		}
	}

	return false;
}
