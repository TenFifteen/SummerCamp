/*
题目大意：
给定两个链表，表示倒着的两个整数。然后将其求和。

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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode ret(0), *head = &ret;
        
        int carry = 0;
        while (l1 || l2) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            head->next = new ListNode(carry%10);
            head = head->next;
            carry /= 10;
        }
        
        if (carry) {
            head->next = new ListNode(carry);
        }
        
        return ret.next;
    }
};