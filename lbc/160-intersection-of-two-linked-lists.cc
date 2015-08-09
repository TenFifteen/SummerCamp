/*
题目大意：
给定两个链表，如果两个链表有交叉，求出交叉点。

解题思路：
先计算出两个链表的长度，然后让长的先走多出来的那段。然后两个链表同时走，如果相同，
就是交叉点，要不然走到最后都没有，就是没有交叉。

遇到的问题：
经典的问题，一次通过。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *tmp = headA;
        while(tmp != NULL){
            tmp = tmp->next;
            lenA++;
        }
        tmp = headB;
        while(tmp != NULL){
            tmp = tmp->next;
            lenB++;
        }
        if(lenA > lenB){
            for(int i = 0; i < lenA-lenB; ++i){
                headA = headA->next;
            }
        }else{
            for(int i = 0; i < lenB-lenA; ++i){
                headB = headB->next;
            }
        }
        while(headA != NULL){
            if(headA == headB)return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};