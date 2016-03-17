/*
题目大意：
给定一个排序的链表，去掉其中重复的元素。

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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode tmp(0), *tail = &tmp;
        
        while (head) {
            int x = head->val;
            if (head->next && head->next->val == x) {
                while (head && head->val == x) head = head->next;
            } else {
                tail->next = head;
                tail = head;
                head = head->next;
            }
        }
        
        tail->next = NULL;
        return tmp.next;
    }
};