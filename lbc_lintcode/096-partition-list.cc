/*
题目：30 % 链表划分 容易

题目大意：
给定一个链表，和一个val
将小于val的放在前面，大于等于val的放在后面。

解题思路：
直接模拟

遇到的问题：没有问题。
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
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode *left_head = NULL, *left_cur = NULL;
        ListNode *right_head = NULL, *right_cur = NULL;
        auto cur = head;
        while (cur != NULL) {
            if (cur->val < x) {
                if (left_head == NULL) {
                    left_head = cur;
                    left_cur = cur;
                } else {
                    left_cur->next = cur;
                    left_cur = cur;
                }
            } else {
                if (right_head == NULL) {
                    right_head = cur;
                    right_cur = cur;
                } else {
                    right_cur->next = cur;
                    right_cur = cur;
                }
            }
            cur = cur->next;
        }
        if (right_cur != NULL) right_cur->next = NULL;
        if (left_cur == NULL) return right_head;
        left_cur->next = right_head;
        return left_head;
    }
};



