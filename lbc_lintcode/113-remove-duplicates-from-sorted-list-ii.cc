/*
题目：27 % 删除排序链表中的重复数字 II 中等

题目大意：
给定一个排序的单链表，删掉其中有重复的元素

解题思路：
遍历

遇到的问题：
就是各种NULL问题。
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *last = head;
        int cnt = 1;
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        head = head->next;
        while (head != NULL) {
            if (head->val != last->val) {
                if (cnt == 1) {
                    if (ret == NULL) {
                        ret = last;
                        cur = last;
                    } else {
                        cur->next = last;
                        cur = last;
                    }
                }
                last = head;
                cnt = 1;
            } else {
                cnt++;
            }
            head = head->next;
        }
        if (cnt == 1) {
            if (ret == NULL) {
                last->next = NULL;
                return last;
            }
            cur->next = last;
            cur = last;
        }
        if (ret == NULL) return NULL;
        cur->next = NULL;
        return ret;
    }
};
