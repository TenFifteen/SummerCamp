/**
 * Problem: You have two numbers represented by a linked list,
 *          where each node contains a single digit. The digits
 *          are stored in reverse order, such that the 1's digit
 *          is at the head of the list. Write a function that adds
 *          the two numbers and returns the sum as a linked list.
 * Solve: use carry to add every non-empty node.
 * Tips: use original node
 */
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
        /**
         * @param l1: the first list
         * @param l2: the second list
         * @return: the sum list of l1 and l2
         */
        ListNode *addLists(ListNode *l1, ListNode *l2) {
            if (l1 == NULL) return l2;
            if (l2 == NULL) return l1;

            int carry = 0;
            ListNode *head = new ListNode(0), *it = head;
            while (l1 || l2 || carry) {
                carry += l1 ? l1->val : 0;
                carry += l2 ? l2->val : 0;

                ListNode *now = NULL;
                if (l1) {
                    now = l1;
                    l1 = l1->next;
                }
                if (l2) {
                    now = l2;
                    l2 = l2->next;
                }
                if (!now) {
                    now = new ListNode(0);
                }

                now->val = carry % 10;
                carry /= 10;

                it->next = now;
                it = now;
            }
            it->next = NULL;

            return head->next;
        }
};
