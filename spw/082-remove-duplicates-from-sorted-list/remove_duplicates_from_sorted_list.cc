/**
 * Problem: Given an sorted list, delete all nodes that have duplicates
 *          leaving only distinct numbers from the original list.
 * Solve: use a new tail and head.
 * Tips: see below
 */
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *new_head = new ListNode(0);
    ListNode *new_tail = new_head;
    ListNode *iter = head;
    int tmp = 0;
    while (iter) {
        if (iter->next && (tmp = iter->next->val) == iter->val) {
            // must guarantee that iter is not null.
            while (iter && iter->val == tmp) {
                iter = iter->next;
            }

        } else {
            new_tail->next = iter;
            new_tail = new_tail->next;
            iter = iter->next;

        }

    }
    new_tail->next = NULL;
    iter = new_head->next;
    delete new_head;
    return iter;
}

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
                bool valid = true;
                while (it->next && it->next->val == it->val) {
                    it = it->next;
                    valid = false;
                }

                if (valid) {
                    ListNode *now = it;

                    tail->next = now;
                    tail = now;
                }

                it = it->next;
            }

            tail->next = NULL;
            return dummy->next;
        }
};
