/**
 * Problem: Given a linked list and a value x, partition it such
 *          that all nodes less than x come before nodes greater than or equal to x.
 *          You should preserve the original relative order of
 *          the nodes in each of the two partitions.
 * Solve: partition && reverse
 * Tips: keep the relative order
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
        ListNode *reverse(ListNode *h) {
            ListNode *nh = NULL;
            while (h) {
                ListNode *now = h;
                h = h->next;

                now->next = nh;
                nh = now;
            }

            return nh;
        }
        /**
         * @param head: The first node of linked list.
         * @param x: an integer
         * @return: a ListNode
         */
        ListNode *partition(ListNode *head, int x) {
            ListNode *h1 = NULL, *h2 = NULL;

            while (head) {
                ListNode *now = head;
                head = head->next;

                if (now->val < x) {
                    now->next = h1;
                    h1 = now;
                } else {
                    now->next = h2;
                    h2 = now;
                }
            }

            h1 = reverse(h1);
            h2 = reverse(h2);

            if (!h1) return h2;

            head = h1;
            while (h1->next) {
                h1 = h1->next;
            }
            h1->next = h2;

            return head;
        }
};



