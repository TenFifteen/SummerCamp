/*
题目大意：
给定两个链表，排序的。然后进行归并

解题思路：
见代码。

遇到的问题：
没有。
*/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode tmp(0), *ret = &tmp;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ret->next = l1;
                ret = l1;
                l1 = l1->next;
            } else {
                ret->next = l2;
                ret = l2;
                l2 = l2->next;
            }
        }
        
        if (l1) ret->next = l1;
        if (l2) ret->next = l2;
        
        return tmp.next;
    }
};