/*
题目大意：
给定一个单链表，翻转它。

解题思路：
直接翻转

遇到的问题：
一次通过。

再次阅读：
比较基础。
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
/*
第二次做：
虽然简单，但是竟然错了那么多遍。真是不应该啊。
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
        if (head == NULL) return NULL;
        
        ListNode *ret = head;
        head = head->next;
        ret->next = NULL;
        while (head) {
            auto next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        return ret;
    }
};