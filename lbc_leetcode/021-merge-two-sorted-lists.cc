/*
题目大意：
给两个有序链表，将其合并为一个有序链表。

解题思路：
遍历两个链表，选当前最小的头结点加入到新的链表中。

遇到的问题：
没有问题，只不过好多判断感觉并不是很爽。

再次阅读：
虽然这道题目的复杂度不会再有提升了，但是可以参考一下下面这种简洁的写法：
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
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
/*
第二次做：
这次做的很顺畅。
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
        ListNode prehead(0);
        ListNode *head = &prehead;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        if (l1) {
            head->next = l1;
        }
        if (l2) {
            head->next = l2;
        }
        
        return prehead.next;
    }
};