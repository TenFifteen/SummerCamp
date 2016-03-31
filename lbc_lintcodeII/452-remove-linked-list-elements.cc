/*
题目大意：
给定一个链表，删除所有val为val的节点。

解题思路：
见代码。

遇到的问题：
 没有。
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
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode tmp(0), *ret = &tmp;
        while (head) {
            if (head->val != val) {
                ret->next = head;
                ret = head;
            }
            head = head->next;
        }
        ret->next = NULL;
        return tmp.next;
    }
};