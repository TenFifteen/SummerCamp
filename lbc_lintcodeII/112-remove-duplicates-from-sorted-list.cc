/*
题目大意：
给定一个排序的链表，将其中重复的元素去掉。

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
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL) return NULL;
        
        ListNode *ret = head, *tail = ret;
        head = head->next;
        
        while (head) {
            if (head->val != tail->val) {
                tail->next = head;
                tail = head;
            }
            head = head->next;
        }
        
        tail->next = NULL;
        return ret;
    }
};