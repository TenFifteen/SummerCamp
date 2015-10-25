/*
题目：44 % 两个链表的交叉 中等

题目大意：
给定两个单链表，问其是否有交叉，有的话找到。保证链表没有环

解题思路：
先计算两个链表的长度，然后将其整理为同样长度，然后同时向前走进行比较

遇到的问题：
没有问题。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        int numa = count(headA);
        int numb = count(headB);
        if (numa == 0 || numb == 0) return NULL;
        if (numa < numb) {
            for (int i = 0; i < (numb-numa); ++i) {
                headB = headB->next;
            }
        } else {
            for (int i = 0; i < (numa-numb); ++i) {
                headA = headA->next;
            }
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    
    int count(ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
};
