/**
 * Problem: Find the nth to last element of a singly linked list.
 *          The minimum number of nodes in list is n.
 * Solve: two pointers.
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
         * @param head: The first node of linked list.
         * @param n: An integer.
         * @return: Nth to last node of a singly linked list.
         */
        ListNode *nthToLast(ListNode *head, int n) {
            ListNode *front = head;
            while (n--) front = front->next;

            ListNode *rear = head;
            while (front) {
                rear = rear->next;
                front = front->next;
            }

            return rear;
        }
};
