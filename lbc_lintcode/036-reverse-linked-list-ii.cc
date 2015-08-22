/*
题目：28 % 翻转链表 II 中等

题目大意：
翻转链表的一部分

解题思路：
找到该部分，然后调用翻转链表子程序

遇到的问题：
没有问题。
*/
/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (head == NULL) return NULL;
        if (m == n) return head;
        auto last = head;
        for (int i = 2; i < m; ++i) {
            last = last->next;
        }
        auto next = head;
        for (int i = 1; i < n; ++i) {
            next = next->next;
        }
        auto tail = next->next;
        next->next = NULL;
        if (m == 1) {
            auto sub = reverse(head);
            last = sub;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = tail;
            return sub;
        } else {
            auto sub = reverse(last->next);
            last->next = sub;
            while (last ->next != NULL) {
                last = last->next;
            }
            last->next = tail;
            return head;
        }
    }
    
    ListNode *reverse(ListNode *head) {
        if (head == NULL) return head;
        auto last = head;
        head = head->next;
        last->next = NULL;
        while (head != NULL) {
            auto tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }
        return last;
    }
};

