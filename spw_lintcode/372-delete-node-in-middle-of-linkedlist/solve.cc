/**
 * Problem: mplement an algorithm to delete a node in the middle
 *          of a singly linked list, given only access to that node.
 * Solve: delete the next node
 * Tips: do not forget to delete the space
 */
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};
