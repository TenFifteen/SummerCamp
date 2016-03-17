/*
题目大意：
翻转链表

解题思路：
见代码

遇到的问题：
没有。
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
        
        ListNode *ret = head;
        head = head->next;
        ret->next = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        
        return ret;
    }
};
