/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     struct ListNode *next;
 ** };
 **/

/**
 *  note the carry and when the length is no equal
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *head = malloc(sizeof(struct ListNode));
	struct ListNode *result = head, *before = result;

	int carry = 0;
	while(l1 && l2) {
		result->val = l1->val + l2->val + carry ;
		if (result->val >= 10) {
			result->val -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		result->next = malloc(sizeof(struct ListNode));

		before = result;
		result = result->next;
		l1 = l1->next;
		l2 = l2->next;
	}

	while(l1) {
		result->val = l1->val  + carry ;
		if (result->val >= 10) {
			result->val -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		result->next = malloc(sizeof(struct ListNode));

		before = result;
		result = result->next;
		l1 = l1->next;
	}

	while(l2) {
		result->val = l2->val + carry ;
		if (result->val >= 10) {
			result->val -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		result->next = malloc(sizeof(struct ListNode));

		before = result;
		result = result->next;
		l2 = l2->next;
	}

	if (!carry) {
		before->next = NULL;
	} else {
		result->val = carry;
		result->next = NULL;
	}

	return head;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        int aside = 0;
        while (l1 || l2) {
            ListNode *now = NULL;
            if (l1) {
                aside += l1->val;
                now = l1;
                l1 = l1->next;
            }

            if (l2) {
                aside += l2->val;
                now = l2;
                l2 = l2->next;
            }

            now->val = aside % 10;
            aside /= 10;
            tail->next = now;
            tail = now;
        }

        if (aside) {
            tail->next = new ListNode(aside);
        } else {
            tail->next = NULL;
        }

        return dummy->next;
    }
};
}
