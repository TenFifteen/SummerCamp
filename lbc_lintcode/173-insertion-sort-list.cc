/*
题目：30 % 链表插入排序 容易

题目大意：
给定一个链表，用插入排序进行排序。

解题思路：
见代码

遇到的问题：
忘记更新head
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
        if (head == NULL) return NULL;
        ListNode *ret = NULL;
        while (head != NULL) {
            auto next = head->next;
            head->next = NULL;
            if (ret == NULL) {
                ret = head;
            } else {
                if (ret->val > head->val) {
                    head->next = ret;
                    ret = head;
                } else {
                    auto cur = ret->next;
                    auto last = ret;
                    while (cur != NULL && cur->val < head->val) {
                        last = cur;
                        cur = cur->next;
                    }
                    last->next = head;
                    head->next = cur;
                }
            }
            head = next;
        }
        return ret;
    }
};
