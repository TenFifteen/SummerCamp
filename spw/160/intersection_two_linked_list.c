/**
 ** Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    struct ListNode *next;
};

int countList(struct ListNode *head) {
	int count = 0;
	while (head) {
		++count;
		head = head->next;
	}
	return count;
}

/**
 * Problem: write a program to find the node at which the intersection of two single linked
 *          lists begins.
 * Solve: similar way with the solution to kth node from the end.
 * Tips: 1A
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = countList(headA);
	int lenB = countList(headB);

	struct ListNode *tempA = headA;
	struct ListNode *tempB = headB;
	int diff = lenA - lenB;
	if (lenA > lenB) {
		while (diff--) {
			tempA = tempA->next;
		}
	} else if (lenA < lenB) {
		diff = -diff;
		while (diff--) {
			tempB = tempB->next;
		}
	}

	while (tempA) {
		if (tempA == tempB) return tempA;
		tempA = tempA->next;
		tempB = tempB->next;
	}

	return NULL;
}
