/*
题目：28 % Reverse Nodes in k-Group new 困难

题目大意：
给定一个单链表，将其按照k个一组进行翻转。最后不足k个的就不翻转了。

解题思路：
就是按照k个一组，翻转，然后拼接。见代码

遇到的问题：
没有问题。
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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        int n = count(head);
        if (n < k || k <= 1) return head;
        ListNode *ret = NULL, *last = NULL;
        for (int i = 0; i < n/k; ++i) {
            auto tail = head;
            for (int j = 0; j < k-1; ++j) {
                tail = tail->next;
            }
            auto next = tail->next;
            tail->next = NULL;
            head = reverse(head);
            if (ret == NULL) {
                ret = head;
                last = ret;
            } else {
                last->next = head;
            }
            while (last->next) {
                last = last->next;
            }
            head = next;
        }
        last->next = head;
        return ret;
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
        if (head == NULL || head->next == NULL) return head;
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
