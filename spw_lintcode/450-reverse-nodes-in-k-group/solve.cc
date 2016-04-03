/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Problem: Given a linked list, reverse the nodes of
 *          a linked list k at a time and return its modified list.
 *          If the number of nodes is not a multiple of k then
 *          left-out nodes in the end should remain as it is.
 * Solve: Reverse twice.
 * Tips: no
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        ListNode *h = NULL;

        int count = 0;
        while (head) {
            ++count;
            ListNode *now = head;
            head = head->next;

            now->next = h;
            h = now;
        }

        int aside = count % k;
        while(aside--) {
            ListNode *now = h;
            h = h->next;

            now->next = head;
            head = now;
        }

        count /= k;
        while (count--) {
            ListNode *it = h;
            int t = k-1;
            while (t--) {
                it = it->next;
            }

            ListNode *last = it->next;
            it->next = head;
            head = h;
            h = last;
        }

        return head;
    }
};
