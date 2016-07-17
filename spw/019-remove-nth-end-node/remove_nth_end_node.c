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
/**
 * use a dummy head node to avoid a aside previous node
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *f1 = dummy, *f2 = dummy;
        while (n--) f1 = f1->next;

        while (f1->next) {
            f1 = f1->next;
            f2 = f2->next;
        }

        ListNode *rm = f2->next;
        f2->next = rm->next;
        delete rm;

        f1 = dummy->next;
        delete dummy;

        return f1;
    }
};
