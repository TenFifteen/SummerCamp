/*
题目：38 % 删除排序链表中的重复元素 容易

题目大意：
给定一个排序的链表，删掉其中重复的元素。

解题思路：
遍历

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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return head;
        auto ret = head;
        head = head->next;
        auto cur = ret;
        while (head != NULL) {
            if (head->val == cur->val) {
                head = head->next;
            } else {
                cur->next = head;
                cur = head;
                head = head->next;
            }
        }
        cur->next = NULL;
        return ret;
    }
};
