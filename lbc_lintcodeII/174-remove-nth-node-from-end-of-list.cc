/*
题目大意：
给定一个链表，删掉倒数第n个节点。返回头结点。

解题思路：
主要是注意如果删掉的是头结点的情况。

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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *front = head;
        for (int i = 0; i < n; ++i) {
            front = front->next;
        }
        
        if (front == NULL) return head->next;
        
        ListNode *tail = head, *last = tail;
        while (front) {
            front = front->next;
            last = tail;
            tail = tail->next;
        }
        
        last->next = tail->next;
        return head;
    }
};


