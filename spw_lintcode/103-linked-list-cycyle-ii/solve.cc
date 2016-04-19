/**
 * Problem: Given a linked list, return the node where the cycle begins.
 *          If there is no cycle, return null.
 * Solve: two pointers
 * Tips: see comments below.
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
         * @param head: The first node of linked list.
         * @return: The node where the cycle begins.
         *           if there is no cycle, return null
         */
        ListNode *detectCycle(ListNode *head) {
            if (head == NULL) return NULL;

            ListNode *it1 = head, *it2 = head;
            // do not use it1 == it2 because they certainly
            // equal at first.
            while (it2) {
                it1 = it1->next;
                it2 = it2->next;

                if (it2) {
                    it2 = it2->next;
                } else {
                    return NULL;
                }

                if (it1 == it2) {
                    break;
                }
            }

            if (!it2) return NULL;

            it1 = head;
            while (it1 != it2) {
                it1 = it1->next;
                it2 = it2->next;
            }

            return it1;
        }
};
