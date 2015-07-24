/*
题目大意：
给定一链表。翻转其中m到n的一段。

解题思路：
找到这一段，翻转。

遇到的问题：
一次通过。
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *last = NULL;
        ListNode *left = NULL, *right = NULL;
        ListNode *next = NULL;
        left = head;
        for(int i = 0; i < m-1; ++i){
            last = left;
            left = left->next;
        }
        right = left;
        for(int i = 0; i < n-m; ++i){
            right = right->next;
        }
        next = right->next;
        right->next = NULL;
        left = reverse(left);
        if(last == NULL){
            head = left;
        }else{
            last->next = left;
        }
        while(left->next != NULL){
            left = left->next;
        }
        left->next = next;
        return head;
    }
    
    ListNode *reverse(ListNode *head){
        ListNode *cur = head;
        ListNode *last = NULL;
        while(cur != NULL){
            ListNode *tmp = cur->next;
            cur->next = last;
            last = cur;
            cur = tmp;
        }
        return last;
    }
};