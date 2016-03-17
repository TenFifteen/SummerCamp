/*
题目大意：
给定一个链表，将其按照x分成两部分。

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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode left(0), right(0), *L = &left, *R = &right;
        
        while (head) {
            if (head->val < x) {
                L->next = head;
                head = head->next;
                L = L->next;
            } else {
                R->next = head;
                head = head->next;
                R = R->next;
            }
        }
        
        R->next = NULL;
        L->next = right.next;
        return left.next;
    }
};


