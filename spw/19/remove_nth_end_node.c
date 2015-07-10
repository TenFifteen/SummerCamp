#include <stdio.h>

/**
 * Problem: delete the nth nodes from the end.
 * Solve: two pointers
 * Tips: when we should delete the first node, the b_pre is not valid,
 *		then we should handle it sepeately.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
	struct ListNode *a = head;
	while (n--) {
		a = a->next;	
	}

	/**
	 * when a is NULL, that is to say, we should delete the first node
	 */
	if (!a) {
		head = head->next;
		return head;
	}

	struct ListNode *b = head, *b_pre = NULL;
	while (*a) {
		b_pre = b;
		b = b->next;	
		a = a->next;	
	}

	b_pre->next = b->next;

	return head;
}

int main()
{
	
}
