/*
题目大意：
给定一个链表，找到其产生环的第一个节点。

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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (head == NULL) return NULL;
        
        ListNode *front = head, *end = head;
        do {
            front = front->next;
            if (front == NULL) return NULL;
            front = front->next;
            end = end->next;
        } while (front && front != end);
        
        if (front == NULL) return NULL;
        
        end = head;
        while (end != front) {
            end = end->next;
            front = front->next;
        }
        
        return front;
    }
};


