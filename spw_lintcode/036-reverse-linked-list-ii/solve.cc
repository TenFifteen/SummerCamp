/**
 * Problem: Reverse a linked list from position m to n.
 * Solve: use a dummy head.
 * Tips: 1. don't forget to let the dummy next point to the head.
 */
/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
    public:
        /**
         * @param head: The head of linked list.
         * @param m: The start position need to reverse.
         * @param n: The end position need to reverse.
         * @return: The new head of partial reversed linked list.
         */
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            ListNode *dummy = new ListNode(0);
            dummy->next = head;

            ListNode *prev = dummy, *it = prev->next;
            n = n - m + 1;
            while (--m) {
                prev = it;
                it = it->next;
            }

            ListNode *r = NULL, *tail = it;

            while (n--) {
                ListNode *now = it;
                it = it->next;

                now->next = r;
                r = now;
            }

            prev->next = r;
            tail->next = it;

            return dummy->next;
        }
};

