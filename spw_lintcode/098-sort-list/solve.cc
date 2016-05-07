/**
 * Problem: Sort a linked list in O(n log n) time using constant space complexity.
 * Solve: split merge
 * Tips: see comments below.
 *       1. when merge, if one list become empty, then we can use another.
 *
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
        ListNode *merge(ListNode *h1, ListNode *h2) {
            ListNode *nh = new ListNode(0), *prev = nh;
            while (h1 || h2) {
                if (!h1) {
                    prev->next = h2;
                    break;
                }

                if (!h2) {
                    prev->next = h1;
                    break;
                }

                if (h1->val < h2->val) {
                    prev->next = h1;
                    h1 = h1->next;
                } else {
                    prev->next = h2;
                    h2 = h2->next;
                }
                prev = prev->next;
            }
            // we need not set prev->next = NULL;
            // because we break when either list is NULL

            h1 = nh->next;
            delete nh;
            return h1;
        }

        int countList(ListNode *h) {
            int cnt = 0;
            while (h) {
                h = h->next;
                cnt++;
            }

            return cnt;
        }
        /**
         * @param head: The first node of linked list.
         * @return: You should return the head of the sorted linked list,
         using constant space complexity.
         */
        ListNode *sortList(ListNode *head) {
            int n = countList(head);
            if (n < 2) return head;

            int half = n / 2;
            ListNode *prev = head, *it = head;

            while (half--) {
                prev = it;
                it = it->next;
            }
            prev->next = NULL;

            ListNode *h1 = sortList(head);
            ListNode *h2 = sortList(it);

            return merge(h1, h2);
        }
};



