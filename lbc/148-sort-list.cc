/*
题目大意：
在nlogn时间复杂度内排序链表。

解题思路：
用归并排序。

遇到的问题：
还是没有能一次通过，不过这次只改了一次就通过了。
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)return NULL;
        if(head->next == NULL)return head;
        int len = 0;
        ListNode *tmp = head;
        while(tmp != NULL){
            len++;
            tmp = tmp->next;
        }
        tmp = head;
        for(int i = 0; i < len/2-1; ++i){
            tmp = tmp->next;
        }
        ListNode *right = sortList(tmp->next);
        tmp->next = NULL;
        head = sortList(head);
        
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        while(head != NULL || right != NULL){
            if(right == NULL){
                cur->next = head;
                head = head->next;
                cur = cur->next;
                cur->next = NULL;
            }else if(head == NULL){
                cur->next = right;
                right = right->next;
                cur = cur->next;
                cur->next = NULL;
            }else{
                if(head->val < right->val){
                    if(ret == NULL){
                        ret = head;
                        cur = head;
                        head = head->next;
                        ret->next = NULL;
                    }else{
                        cur->next = head;
                        head = head->next;
                        cur = cur->next;
                        cur->next = NULL;
                    }
                }else{
                    if(ret == NULL){
                        ret = right;
                        cur = ret;
                        right = right->next;
                        ret->next = NULL;
                    }else{
                        cur->next = right;
                        right = right->next;
                        cur = cur->next;
                        cur->next = NULL;
                    }
                }
            }
        }
        return ret;
    }
};