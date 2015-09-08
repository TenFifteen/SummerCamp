/*
题目：27 % 链表排序 中等

题目大意：
给定一个链表，要求在nlogn时间内对链表排序，不适用额外空间。

解题思路：
归并排序

遇到的问题：
没有问题。
不过竟然将ret写成了head，调试了半天。
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return head;
        int len = 0;
        auto cur = head;
        while (cur != NULL) {
            len++;
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < (len-1)/2; ++i) {
            cur = cur->next;
        }
        auto right = sortList(cur->next);
        cur->next = NULL;
        auto left = sortList(head);
        ListNode *ret = NULL;
        cur = NULL;
        while (left != NULL || right != NULL) {
            if (left == NULL) {
                cur->next = right;
                return ret;
            }
            if (right == NULL) {
                cur->next = left;
                return ret;
            }
            if (left->val <= right->val) {
                if (ret == NULL) {
                    ret = left;
                    cur = left;
                } else {
                    cur->next = left;
                    cur = left;
                }
                left = left->next;
            } else {
                if (ret == NULL) {
                    ret = right;
                    cur = right;
                } else {
                    cur->next = right;
                    cur = right;
                }
                right = right->next;
            }
        }
        return ret;
    }
};



