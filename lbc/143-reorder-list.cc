/*
题目大意：
给定一个单链表，将其元素按照1-》n -》2-》n-1-》3-》n-2.。。的次序排列。原地修改链表，
不可以申请额外空间，也不可以改变指针的内容，只可以改变指针。

解题思路：
将链表的后半部分翻转，然后进行链表的归并。

遇到的问题：
还是链表指针修改次序的问题，又搞了我好久。这东西真烦人，一定要够细心。
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)return;
        int len = 0;
        ListNode *tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            len++;
        }
        tmp = head;
        for(int i = 0; i < (len-1)/2; ++i){
            tmp = tmp->next;
        }
        ListNode *right = reverse(tmp->next);
        tmp->next = NULL;
        tmp = head;
        head = head->next;
        tmp->next = right;
        tmp = tmp->next;
        right = right->next;
        while(head != NULL || right != NULL){
            if(head != NULL){
                tmp->next = head;
                head = head->next;
                tmp = tmp->next;
            }
            if(right != NULL){
                tmp->next = right;
                right = right->next;
                tmp = tmp->next;
            }
        }
    }
    
    ListNode *reverse(ListNode *head){
        if(head == NULL)return head;
        ListNode *last = head;
        head = head->next;
        last->next = NULL;
        while(head != NULL){
            ListNode *tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }
        return last;
    }
};