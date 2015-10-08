/*
题目：48 % 带环链表 中等

题目大意：
给定一个链表，可能其中有环，判断是否有环

解题思路：
两个指针，一个一次走两步，一个一次走一步，如果前面的指针赶上了后面的指针，那么就是有环。

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
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if (head == NULL) return false;
        auto front = head;
        auto end = head->next;
        while (end != NULL) {
            if (end == front) return true;
            end = end->next;
            if (end == NULL) return false;
            end = end->next;
            front = front->next;
        }
        return false;
    }
};



