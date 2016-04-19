/**
 * Problem: Given a sorted linked list, delete all duplicates such that each element appear only once.
 * Solve: two poniters.
 * Tips: the time to update p
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
         * @return: head node
         */
        ListNode *deleteDuplicates(ListNode *head) {
            ListNode *it = head, **p = &head;

            while (it) {
                while (it->next && it->next->val == it->val) {
                    it = it->next;
                }

                *p = it;
                p = &it->next;
                it = it->next;
            }

            return head;
        }
};
