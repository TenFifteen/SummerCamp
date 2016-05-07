/**
 * Problem: Given a linked list, determine if it has a cycle in it.
 * Solve: two pointers.
 * Tips: judge equal in the loop instead of the while condition.
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
         * @return: True if it has a cycle, or false
         */
        bool hasCycle(ListNode *head) {

            ListNode *it1 = head, *it2 = head;

            while (it2) {
                it1 = it1->next;
                it2 = it2->next;

                if (it2) {
                    it2 = it2->next;
                } else {
                    return false;
                }

                if (it2 == it1) return true;
            }

            return false;
        }
};
