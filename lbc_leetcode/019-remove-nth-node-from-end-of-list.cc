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

再次阅读：
这个题也是经典老题了。解法基本就是两个指针了。
再写也就是写的过程中需要注意一下风格，边界等各种问题。
有人直接用指向指针的指针做的，就可以避免单独处理head的问题了。
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
/*
第二次做：
感觉这次做的要清晰好多了。
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
        ListNode prehead(0);
        prehead.next = head;

        ListNode *last = &prehead, *cur = &prehead, *front = &prehead;
        for (int i = 0; i < n; ++i) {
            front = front->next;
        }
        while (front) {
            front = front->next;
            last = cur;
            cur = cur->next;
        }

        last->next = cur->next;
        delete cur;

        return prehead.next;
    }
};
/*
 * 不错
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
        ListNode tmp(0);
        ListNode *pre = &tmp;
        pre->next = head;

        ListNode *front = pre;
        for (int i = 0; i < n; ++i) front = front->next;

        ListNode *cur = pre, *last;
        while (front) {
            front = front->next;
            last = cur;
            cur = cur->next;
        }

        last->next = cur->next;
        delete cur;

        return pre->next;
    }
};
