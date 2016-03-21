/**
 * Problem: Remove all elements from a linked list of integers that have value val.
 * Solve: Dummy head
 * Tips: no
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
         * @param head a ListNode
         * @param val an integer
         * @return a ListNode
         */
        ListNode *removeElements(ListNode *head, int val) {
            // Write your code here
            ListNode *h = new ListNode(0);
            h->next = head;
            ListNode *prev = h;

            while (prev->next) {
                if (prev->next->val == val) {
                    ListNode *tmp = prev->next;
                    prev->next = tmp->next;
                    delete tmp;
                } else {
                    prev = prev->next;
                }
            }

            prev = h->next;
            delete h;
            return prev;
        }
};
