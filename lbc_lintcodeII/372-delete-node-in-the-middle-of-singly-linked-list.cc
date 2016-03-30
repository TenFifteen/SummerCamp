/*
题目大意：
给定一个链表的节点，删除该节点。

解题思路：
见代码。

遇到的问题：
没有。
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        node->val = node->next->val;
        ListNode *del = node->next;
        node->next = del->next;
        delete del;
    }
};