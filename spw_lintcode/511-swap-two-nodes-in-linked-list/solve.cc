/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Problem: Given a linked list and two values v1 and v2. Swap
 *          the two nodes in the linked list with values v1 and
 *          v2. It's guaranteed there is no duplicate values in
 *          the linked list. If v1 or v2 does not exist in the
 *          given linked list, do nothing.
 * Solve: find all their previous and use dummy head.
 * Tips: Special case: node1->next == node2
 */
class Solution {
    public:
        /**
         * @param head a ListNode
         * @oaram v1 an integer
         * @param v2 an integer
         * @return a new head of singly-linked list
         */
        ListNode* swapNodes(ListNode* head, int v1, int v2) {
            // Write your code here
            ListNode *prev1 = NULL, *prev2 = NULL;

            ListNode *h = new ListNode(0);
            h->next = head;
            ListNode *it = h;

            while (it->next) {
                int val = it->next->val;
                if (val == v1 || val == v2) {
                    if (prev1 == NULL) {
                        prev1 = it;
                    } else {
                        prev2 = it;
                    }
                }

                it = it->next;
            }

            if (prev1 == NULL || prev2 == NULL) return head;


            ListNode *node1 = prev1->next;
            ListNode *node2 = prev2->next;

            if (prev1->next == prev2) {
                prev2->next = node2->next;
                node2->next = node1;
                prev1->next = node2;
            } else {
                prev2->next = node2->next;
                node2->next = node1->next;
                prev1->next = node2;

                node1->next = prev2->next;
                prev2->next = node1;
            }

            return h->next;
        }
};
