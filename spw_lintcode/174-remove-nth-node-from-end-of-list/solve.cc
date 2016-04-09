/**
 * Problem: Given a linked list, remove the nth node from the end of list and return its head.
 * Solve: use a dummy head node.
 * Tips: see comments below
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
         * @param n: An integer.
         * @return: The head of linked list.
         */
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            if (n <= 0) return head;

            ListNode *tail = head;
            while (n--) tail = tail->next;

            // handle when n = length(head)
            if (!tail) {
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
                return head;
            }

            ListNode *it = head;
            while (tail->next) {
                tail = tail->next;
                it = it->next;
            }

            ListNode *tmp = it->next;
            it->next = it->next->next;

            delete tmp;
            return head;
        }
};



