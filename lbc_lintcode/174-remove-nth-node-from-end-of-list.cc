/*
题目：28 % 删除链表中倒数第n个节点 容易

题目大意：
给定一个链表，删除倒数第n个节点。

解题思路：
见代码

遇到的问题：
没有问题。
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if (head == NULL) return NULL;
        int total = count(head);
        if (n == total) {
            auto ret = head->next;
            delete head;
            return ret;
        }
        ListNode *last = head, *cur = head->next;
        for (int i = 0; i < total-n-1; ++i) {
            last = cur;
            cur = cur->next;
        }
        last->next = cur->next;
        delete cur;
        return head;
    }
    
    int count(ListNode *head) {
        int cnt = 0;
        while (head != NULL) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
};



