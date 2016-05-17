/**
 * Problem: Reverse a linked list.
 * Solve: just do it
 * Tips: no
 */
/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
    public:
        /**
         * @param head: The first node of linked list.
         * @return: The new head of reversed linked list.
         */
        ListNode *reverse(ListNode *head) {
            ListNode *r = NULL;
            while (head) {
                ListNode *now = head;
                head = head->next;

                now->next = r;
                r = now;
            }

            return r;
        }
};

