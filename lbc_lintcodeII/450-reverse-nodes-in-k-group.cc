/*
题目大意：
给定一个链表，将其k个一组进行翻转。

解题思路：
先计算链表的长度，然后逐段翻转。

遇到的问题：
还是边界问题。
将k %= len之后，判断k==0就直接返回了。实际上应该是可能k == n来着。
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
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode *reverse(ListNode *head) {
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
    
public:
    /**
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        int len = count(head);
        if (k <= 0 || k > len) return head;
        k %= len;
        if (k == 0) k = len;
        
        ListNode tmp(0), *tail = &tmp;
        while (head) {
            tail->next = head;
            
            int num = 1;
            while (head && num < k) {
                head = head->next;
                num++;
            }
            
            if (num == k && head != NULL) {
                ListNode *next = head->next, *tt = tail->next;
                head->next = NULL;
                tail->next = reverse(tail->next);
                
                tail = tt;
                tail->next = next;
                head = next;
            }
        }
        
        return tmp.next;
    }
};