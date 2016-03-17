/*
题目大意：
给定一个链表，将其排列成1->n->2->n-1->...这样子

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
    int count(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *ret = NULL;
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
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        int n = count(head);
        if (n < 2) return;
        
        ListNode *tail = head;
        for (int i = 0; i < (n-1)/2; ++i) {
            tail = tail->next;
        }
        
        ListNode *right = reverse(tail->next);
        tail->next = NULL;
        
        ListNode tmp(0), *ret = &tmp;
        while (head) {
            ret->next = head;
            ret = head;
            head = head->next;
            
            if (right) {
                ret->next = right;
                ret = right;
                right = right->next;
            }
        }
    }
};


