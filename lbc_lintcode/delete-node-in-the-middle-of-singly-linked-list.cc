/*
题目：37 % 在O(1)时间复杂度删除链表节点 容易

题目大意：
给定一个链表中的节点，并且不是最后一个节点，然后删掉该节点。

解题思路：
将该节点的下一个节点删掉

遇到的问题：
没有问题。
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
        auto tmp = node->next;
        node->next = node->next->next;
        delete tmp;
    }
};
