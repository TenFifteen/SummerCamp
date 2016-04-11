/**
 * Problem: Merge two sorted (ascending) linked lists and return
 *         it as a new sorted list. The new sorted list should be
 *         made by splicing together the nodes of the two lists
 *         and sorted in ascending order.
 * Solve: use a dummy head node.
 * Tips: no
 */
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
    public:
        /**
         * @param ListNode l1 is the head of the linked list
         * @param ListNode l2 is the head of the linked list
         * @return: ListNode head of linked list
         */
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            ListNode *head = new ListNode(0), *it = head;

            while (l1 || l2) {
                ListNode *now = NULL;

                if (!l1) {
                    now = l2;
                    l2 = l2->next;
                } else if (!l2 || l1->val < l2->val) {
                    now = l1;
                    l1 = l1->next;
                } else {
                    now = l2;
                    l2 = l2->next;
                }

                it->next = now;
                it = now;
            }

            return head->next;
        }
};
