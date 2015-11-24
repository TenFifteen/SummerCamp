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
