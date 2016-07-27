/**
 ** Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Problem: Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 *          reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * Solve: get the back half of the list and resverse it, then
 *        merge it with the front half list.
 * Tips: see below
 */
void reorderList(struct ListNode* head) {
	if (head == NULL) return NULL;

	struct ListNode* end = head;
	int count = 0;
	while (end) {
		count++;
		end = end->next;
	}
	end = head;
	count /= 2;
	while (count--) {
		end = end->next;
	}

	// abort the middle node, because it needn't move
	struct ListNode* back = end->next;
	if (back == NULL) return head;
	end->next = NULL;


	struct ListNode* head2 = NULL;
	while (back) {
		struct ListNode* temp = back;
		back = back->next;

		temp->next = head2;
		head2 = temp;
	}

	end = head;
	while (end && head2) {
		struct ListNode* temp1 = end;
		struct ListNode* temp2 = head2;
		end = end->next;
		head2 = head2->next;

		temp2->next = temp1->next;
		temp1->next = temp2;
	}


	return head;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        // handle the odd length to avoid it1 moving more
        ListNode *it1 = head, *it2 = head;
        while (it2 && it2->next) {
            it1 = it1->next;
            it2 = it2->next;
            if (it2) it2 = it2->next;
        }


        // use the next as the head of the other side.
        it2 = it1->next;
        it1->next = NULL;
        ListNode *h = NULL;
        while (it2) {
            ListNode *tmp = it2;
            it2 = it2->next;

            tmp->next = h;
            h = tmp;
        }


        it1 = head; it2 = h;
        while (it2) {
            ListNode *tmp = it2;
            it2 = it2->next;

            tmp->next = it1->next;
            it1->next = tmp;

            it1 = tmp->next;
        }
    }
};
