/*
题目：27 % Remove Linked List Elements new 入门

题目大意：
给定一个单链表，删掉其中所有等于val的节点

解题思路：
直接遍历

遇到的问题：
没有问题。
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
        ListNode *ret = NULL, *cur = NULL;
        while (head != NULL) {
            if (head->val != val) {
                if (ret == NULL) {
                    ret = head;
                    cur = head;
                } else {
                    cur->next = head;
                    cur = head;
                }
            }
            head = head->next;
        }
        if (ret == NULL) return ret;
        cur->next = NULL;
        return ret;
    }
};
