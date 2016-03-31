/*
题目大意：
给定一个链表，两两交换链表中的节点。

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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        ListNode tmp(0), *ret = &tmp;
        
        while (head) {
            if (head->next) {
                ret->next = head->next;
                ret = ret->next;
                ListNode *next = head->next->next;
                ret->next = head;
                ret = head;
                head = next;
            } else {
                ret->next = head;
                ret = head;
                head = head->next;
            }
        }
        
        ret->next = NULL;
        return tmp.next;
    }
};