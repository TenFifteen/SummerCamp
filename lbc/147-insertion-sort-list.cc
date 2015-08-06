/*
题目大意：
给定一个单链表。用插入排序进行排序。

解题思路：
直接插入排序就是了。

遇到的问题：
链表操作经过上一道题的联系，感觉这道题错误少了很多。
但是还是没能一次通过。
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)return head;
        ListNode *ret = head;
        head = head->next;
        ret->next = NULL;
        while(head != NULL){
            ListNode *next = head->next;
            if(head->val <= ret->val){
                head->next = ret;
                ret = head;
            }else{
                ListNode *tmp = ret;
                ListNode *last = ret;
                while(tmp != NULL && tmp->val < head->val){
                    last = tmp;
                    tmp = tmp->next;
                }
                if(tmp == NULL){
                    last->next = head;
                    head->next = NULL;
                }else{
                    last->next = head;
                    head->next = tmp;
                }
            }
            head = next;
        }
        return ret;
    }
};