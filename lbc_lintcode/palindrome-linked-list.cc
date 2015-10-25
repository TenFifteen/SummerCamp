/*
题目：29 % 回文链表 new 中等

题目大意：
给定一个单链表，判断其是否是回文的。O（n）的时间复杂度，O（1）的空间复杂度

解题思路：
将链表的后半部分翻转过来，然后跟前半部分进行比较

遇到的问题：
虽然感觉这样做需要破坏原来的链表结构，但是好像找不到更好的方法达到题目的空间、
时间复杂度的要求了。

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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if (head == NULL) return true;
        if (head->next == NULL) return true;
        int n = count(head);
        ListNode *last = head;
        ListNode *right = head;
        for (int i = 0; i < (n+1)/2; ++i) {
            last = right;
            right = right->next;
        }
        right = reverse(right);
        last->next = NULL;
        for (int i = 0; i < n/2; ++i) {
            if (head->val != right->val) return false;
            head = head->next;
            right = right->next;
        }
        return true;
    }
    
    int count(ListNode *head) {
        int ret = 0;
        while (head) {
            ret++;
            head = head->next;
        }
        return ret;
    }
    
    ListNode *reverse(ListNode *head) {
        if (head == NULL) return head;
        ListNode *ret = NULL;
        while (head) {
            auto next = head->next;
            if (ret == NULL) {
                ret = head;
                ret->next = NULL;
            } else {
                head->next = ret;
                ret = head;
            }
            head = next;
        }
        return ret;
    }
};
