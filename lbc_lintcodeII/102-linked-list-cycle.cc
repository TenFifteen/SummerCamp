/*
题目大意：
给定一个链表，判断其中是否有环。

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
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if (head == NULL) return false;
        
        ListNode *front = head->next;
        while (front && front != head) {
            front = front->next;
            if (front == NULL) return false;
            front = front->next;
            head = head->next;
        }
        
        return front == head;
    }
};


