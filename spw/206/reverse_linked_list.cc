#include <string>

/**
 * Problem: Reverse a singly linked list.
 * Solve: Reverse a singly linked list.
 * Tip: no
 */
ListNode* reverseList(ListNode* head) {
    ListNode *new_head = NULL;
    ListNode *iter = head;
    while (iter) {
        ListNode *now = iter;
        iter = iter->next;

        now->next = new_head;
        new_head = now;

    }
    return new_head;

}
