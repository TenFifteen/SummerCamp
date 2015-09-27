/*
题目：38 % 合并两个排序链表 容易

题目大意：
给定两个排序的链表，将其归并

解题思路：
直接归并

遇到的问题：
没有问题。
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
        ListNode *ret = NULL, *cur = NULL;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                if (ret == NULL) {
                    return l2;
                } else {
                    cur->next = l2;
                    return ret;
                }
            }
            if (l2 == NULL) {
                if (ret == NULL) {
                    return l1;
                } else {
                    cur->next = l1;
                    return ret;
                }
            }
            if (l1->val < l2->val) {
                if (ret == NULL) {
                    ret = l1;
                    cur = ret;
                } else {
                    cur->next = l1;
                    cur = l1;
                }
                l1 = l1->next;
            } else {
                if (ret == NULL) {
                    ret = l2;
                    cur = ret;
                } else {
                    cur->next = l2;
                    cur = l2;
                }
                l2 = l2->next;
            }
        }
        return ret;
    }
};
