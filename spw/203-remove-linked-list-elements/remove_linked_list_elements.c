/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     struct ListNode *next;
 ** };
 **/
/**
 * Problem: remove all elements from a linked list of integers that have value val;
 * Solve: use a dummy head node and a previous pointer.
 * Tips: see below
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* dummy = malloc(sizeof(struct ListNode));

	struct ListNode* pre = dummy;
	pre->next = head;

	struct ListNode* it = head;
	while (it) {
		if (it->val == val) {
			pre->next = it->next;

			// the head must keep up with
			if (head == it) {
				head = it->next;
			}
			free(it);
			it = pre->next;
		} else {
			pre = it;
			it = it->next;
		}
	}

	free(dummy);
	return head;
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *it = &dummy;
        while (it->next) {
            if (it->next->val == val) {
                ListNode *del = it->next;
                it->next = del->next;

                delete del;
            } else
                it = it->next;
        }

        return dummy.next;
    }
};
