/**
 * Problem: Given a singly linked list L: L0 → L1 → … → Ln-1 → Ln
 *          reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 * Solve: split, reverse, merge
 * Tips: split the in the position half = (n+1)/2; merge two nodes every time
 *       in order.
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
        int countList(ListNode *head) {
            int cnt = 0;
            while (head) {
                ++cnt;
                head = head->next;
            }

            return cnt;
        }
        /**
         * @param head: The first node of linked list.
         * @return: void
         */
        void reorderList(ListNode *head) {
            int n = countList(head);
            if (n < 2) return;

            int half = (n+1) / 2;

            // split
            ListNode *prev = head, *it = head;
            while (half--) {
                prev = it;
                it = it->next;
            }
            prev->next = NULL;

            // reverse
            ListNode *h = NULL;
            while (it) {
                ListNode *now = it;
                it = it->next;

                now->next = h;
                h = now;
            }

            // merge
            ListNode *nh = new ListNode(0);
            prev = nh;
            while (head || h) {
                if (head) {
                    prev->next = head;
                    head = head->next;
                    prev = prev->next;
                }

                if (h) {
                    prev->next = h;
                    h = h->next;
                    prev = prev->next;
                }
            }
            prev->next = NULL;

            head = nh->next;
            delete nh;
        }
};



