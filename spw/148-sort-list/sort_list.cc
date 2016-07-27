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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *merge(ListNode *h1, ListNode *h2) {
        static ListNode dummy(0);

        ListNode *tail = &dummy;
        while (h1 || h2) {
            ListNode *tmp = NULL;
            if (h2 == NULL || h1 && h1->val < h2->val) {
                tmp = h1;
                h1 = h1->next;
            } else {
                tmp = h2;
                h2 = h2->next;
            }
            tail->next = tmp;
            tail = tmp;
        }
        tail->next = NULL;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // important!!
        // if the length = 2
        // then the left length will always be 2
        static ListNode dummy(0);
        dummy.next = head;

        ListNode *it1 = &dummy, *it2 = &dummy;
        while (it2 && it2->next) {
            it1 = it1->next;
            it2 = it2->next->next;
        }

        ListNode *h = it1->next;
        it1->next = NULL;
        ListNode *left = sortList(head), *right = sortList(h);
        return merge(left, right);
    }
};
