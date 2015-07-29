/*
题目大意：
给定一个链表，让把所有相邻的数据交换过来。而且不可以交换值，只能交换指针；而且只可以遍历一遍。

解题思路：
直接找到两个元素，然后就交换之。但是要注意很多边界条件。

遇到的问题：
在返回的链表的最后一定要赋值为NULL。要不然就是死循环。
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode *ret = head->next;
        ListNode *cur = ret->next;
        ret->next = head;
        ListNode *last = head;
        head->next = NULL; // dead loop
        while(cur != NULL){
            if(cur->next == NULL){
                last->next = cur;
                break;
            }
            ListNode *tmp = cur->next->next;
            last->next = cur->next;
            last = last->next;
            last->next = cur;
            last = cur;
            last->next = NULL; //dead loop
            cur = tmp;
        }
        return ret;
    }
};