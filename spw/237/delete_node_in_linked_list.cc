/**
 * Problem: Write a function to delete a node (except the tail)
 *          in a singly linked list, given only access to that node.
 * Solve: copy the value of next node to the current, then delete
 *        the next one.
 * Tips: no
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode *next = node->next;
        node->next = node->next->next;
        delete next;
    }
};
