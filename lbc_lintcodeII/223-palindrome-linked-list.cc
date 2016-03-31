/*
题目大意：
给定一个聊表，判断这个链表是不是回文的。

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
    int count(ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *ret = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        return ret;
    }
    
public:
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        int len = count(head);
        if (len < 2) return true;
        
        ListNode *tail = head;
        for (int i = 0; i < (len-1)/2; ++i) {
            tail = tail->next;
        }
        
        ListNode *right = reverse(tail->next);
        tail->next = NULL;
        
        while (head && right) {
            if (head->val != right->val) return false;
            head = head->next;
            right = right->next;
        }
        return true;
    }
};