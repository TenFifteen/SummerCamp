/*
题目大意：
给定一个链表，进行插入排序。

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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode ret(0);
        
        while (head) {
            ListNode *next = head->next;
            
            ListNode *last = &ret, *cur = last->next;
            while (cur && cur->val < head->val) {
                last = cur;
                cur = cur->next;
            }
            last->next = head;
            head->next = cur;
            
            head = next;
        }
        
        return ret.next;
    }
};