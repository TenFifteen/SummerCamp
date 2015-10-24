/*
题目：34 % Swap Nodes in Pairs new 容易

题目大意：
给定一个单链表，将其挨着的两个元素交换

解题思路：
直接做，见代码

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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if (head == NULL || head->next == NULL) return head;
        ListNode *ret = NULL, *cur = NULL;
        while (head != NULL) {
            if (head->next == NULL) {
                cur->next = head;
                return ret;
            } else {
                if (ret == NULL) {
                    auto next = head->next->next;
                    ret = head->next;
                    ret->next = head;
                    cur = ret->next;
                    head = next;
                } else {
                    auto next = head->next->next;
                    cur->next = head->next;
                    cur->next->next = head;
                    cur = head;
                    head = next;
                }
            }
        }
        cur->next = NULL;
        return ret;
    }
};
