/*
题目：26 % 旋转链表 中等

题目大意：
给定一个单链表，将其向右移动k位

解题思路：
直接做

遇到的问题：
一定要注意取模的时候，后面的数不能是0，就跟除法一样。
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
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        int n = count(head);
        if (n == 0) return head;
        k %= n;
        if (k == 0) return head;
        ListNode *tail = head;
        ListNode *ret = head;
        for (int i = 0; i < n-k; ++i) {
            tail = ret;
            ret = ret->next;
        }
        tail->next = NULL;
        tail = ret;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = head;
        return ret;
    }
    
    int count(ListNode *head) {
        int cnt = 0;
        while (head != NULL) {
            cnt ++;
            head = head->next;
        }
        return cnt;
    }
};
