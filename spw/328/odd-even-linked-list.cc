/**
 * Problem: Given a singly linked list, group all odd nodes together
 *          followed by the even nodes. Please note here we are talking
 *          about the node number and not the value in the nodes.
 * Solve: two pointers
 * Tips: no
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
        ListNode* oddEvenList(ListNode* head) {
            ListNode *odd = new ListNode(0), *even = new ListNode(0);

            ListNode *it = head;
            ListNode *tail1 = odd, *tail2 = even;

            while (it) {
                tail1->next = it;
                tail1 = it;
                it = it->next;

                if (!it) break;

                tail2->next = it;
                tail2 = it;
                it = it->next;
            }

            tail1->next = even->next;
            tail2->next = NULL;
            return odd->next;
        }
};
