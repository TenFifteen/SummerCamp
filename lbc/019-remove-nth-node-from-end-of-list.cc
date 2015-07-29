/*
题目大意：
给一个链表。删除倒数第n个数。保证n是有效的。要求对链表遍历一遍。

解题思路：
弄三个指针，一个在前，一个是cur，一个是last。
pre和cur之间差n个位置，所以当pre到了NULL的时候，cur就是要被删掉的。
last是用来记录cur的前一个节点的。

遇到的问题：
这个问题是一个很经典的老问题了，好像是编程之美里就有吧。
我最喜欢这样的链表题目了。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head;
        ListNode *pre = head;
        ListNode *last = head;
        for(int i = 0; i < n; ++i){
            pre = pre->next;
        }
        while(pre != NULL){
            last = cur;
            pre = pre->next;
            cur = cur->next;
        }
        if(cur == head){
            cur = head->next;
            delete head;
            return cur;
        }else{
            last->next = cur->next;
            delete cur;
            return head;
        }
    }
};