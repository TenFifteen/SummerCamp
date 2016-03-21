/**
 * Problem: Given a linked list, swap every two adjacent nodes and return its head.
 * Solve: Dummy head pointer and two pointers.
 * Tips: carefully update the two pointers
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
         * @return a ListNode
         */
        ListNode* swapPairs(ListNode* head) {
            // Write your code here
            ListNode *h = new ListNode(0);
            h->next = head;

            ListNode *prev1 = h, *prev2 = head;

            while (prev1->next && prev2->next) {
                ListNode *last = prev2->next->next;

                ListNode *node2 = prev2->next;
                prev1->next = node2;
                node2->next = prev2;
                prev2->next = last;

                prev1 = prev2;
                prev2 = last;
                if (prev2 == NULL) break;
            }

            head = h->next;
            delete h;

            return head;
        }
};
