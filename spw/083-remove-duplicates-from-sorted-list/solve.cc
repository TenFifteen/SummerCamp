/**
 * Problem: Given a sorted linked list, delete all duplicates such that each element appear only once.
 * Solve: no
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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode *dummy = new ListNode(0);
            ListNode *tail = dummy, *it = head;

            while (it) {
                while (it->next && it->next->val == it->val) {
                    it = it->next;
                }

                if (it) {
                    ListNode *now = it;
                    it = it->next;

                    tail->next = now;
                    tail = now;
                }
            }
            tail->next = NULL;
            return dummy->next;
        }
};
