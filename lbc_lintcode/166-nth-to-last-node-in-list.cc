/*
题目：41 % 链表倒数第n个节点 容易

题目大意：
给定一个单链表，求其倒数第n个元素

解题思路：
两指针

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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        auto cur = head;
        for (int i = 0; i < n; ++i) {
            cur = cur->next;
        }
        while (cur != NULL) {
            cur = cur->next;
            head = head->next;
        }
        return head;
    }
};



