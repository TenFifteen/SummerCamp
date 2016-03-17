/*
题目大意：
给定一个链表，将其中m到n的节点翻转。

解题思路：
见代码

遇到的问题：
没有太大问题。
*/
/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
    ListNode *reverse(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode *ret = head;
        head = head->next;
        ret->next = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        
        return ret;
    }
    
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (head == NULL) return head;
        
        ListNode tmp(0), *ret = &tmp;
        ret->next = head;
        
        ListNode *front = ret;
        for (int i = 0; i < n-m; ++i) {
            front = front->next;
        }
        
        ListNode *last, *next;
        head = ret;
        for (int i = 0; i < m; ++i) {
            last = head;
            head = head->next;
            front = front->next;
        }
        next = front->next;
        front->next = NULL;
        
        last->next = reverse(head);
        head->next = next;
        return ret->next;
    }
};
