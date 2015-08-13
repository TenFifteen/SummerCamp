/*
题目大意：
给定一个单链表，翻转它。

解题思路：
直接翻转

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return head;
        ListNode *ret = head;
        head = head->next;
        ret->next = NULL;
        while(head != NULL){
            auto tmp = head->next;
            head->next = ret;
            ret = head;
            head = tmp;
        }
        return ret;
    }
};