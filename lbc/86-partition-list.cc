/*
题目大意：
给定一个链表，无序。给定一个整数x，将链表partition，比x小的放到左边；
剩下的放到右边。并且保持原来的顺序。

解题思路：
链表的题目。

遇到的问题：
一次通过。注意边界。
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)return head;
        ListNode *left = NULL, *right = NULL;
        ListNode *left_tail = NULL, *right_tail = NULL;
        while(head){
            if(head->val < x){
                if(left == NULL){
                    left = head;
                    left_tail = left;
                }else{
                    left_tail->next = head;
                    left_tail = left_tail->next;
                }
                head = head->next;
            }else{
                if(right == NULL){
                    right = head;
                    right_tail = right;
                    head = head->next;
                    right_tail->next = NULL;
                }else{
                    right_tail->next = head;
                    right_tail = right_tail->next;
                    head = head->next;
                    right_tail->next = NULL;
                }
            }
        }
        if(left_tail == NULL)return right;
        left_tail->next = right;
        return left;
    }
};