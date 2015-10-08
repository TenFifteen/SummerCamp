/*
题目：41 % 翻转链表 容易

题目大意：
翻转链表

解题思路：
直接翻转

遇到的问题：
没有问题。
*/
/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if (head == NULL) return NULL;
        ListNode *last = head;
        head = head->next;
        last->next = NULL;
        while (head != NULL) {
            auto tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }
        return last;
    }
};

