/**
 * Problem: Sort a linked list using insertion sort.
 * Solve: use a dummy head
 * Tips: see comments below.
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode *h = new ListNode(0);
        h->next = head;

        while (head) {
            ListNode *now = head;
            head = head->next;

            ListNode* prev = h;
            while (prev->next && now->val > prev->next->val)
                prev = prev->next;
            now->next = prev->next;
            // the prev is previous node of now
            prev->next = now;
        }

        ListNode *tmp = h;
        h = h->next;
        delete tmp;
        return h;
    }
};
