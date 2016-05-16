/*
题目大意：
给链表做移位。

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
    int getLength(ListNode *root) {
        int cnt = 0;
        while (root) {
            cnt++;
            root = root->next;
        }
        return cnt;
    }
    
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (head == NULL) return NULL; // %0 can be serious problem.
        int len = getLength(head);
        
        k %= len;
        if (k == 0) return head;
        
        ListNode *ret = head, *tail = head;
        for (int i = 0; i < len-k; ++i) {
            tail = ret;
            ret = ret->next;
        }
        tail->next = NULL;
        
        tail = ret;
        while (tail->next) {
            tail = tail->next;
        }
        
        tail->next = head;
        return ret;
    }
};
