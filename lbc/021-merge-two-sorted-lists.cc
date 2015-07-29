/*
题目大意：
给两个有序链表，将其合并为一个有序链表。

解题思路：
遍历两个链表，选当前最小的头结点加入到新的链表中。

遇到的问题：
没有问题，只不过好多判断感觉并不是很爽。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                if(ret == NULL){
                    return l2;
                }else{
                    cur->next = l2;
                    return ret;
                }
            }
            if(l2 == NULL){
                if(ret == NULL){
                    return l1;
                }else{
                    cur->next = l1;
                    return ret;
                }
            }
            if(l1->val < l2->val){
                if(ret == NULL){
                    ret = l1;
                    cur = l1;
                    l1 = l1->next;
                }else{
                    cur->next = l1;
                    cur = l1;
                    l1 = l1->next;
                }
            }else{
                if(ret == NULL){
                    ret = l2;
                    cur = l2;
                    l2 = l2->next;
                }else{
                    cur->next = l2;
                    cur = l2;
                    l2 = l2->next;
                }
            }
        }
        return ret;
    }
};