/*
题目：22 % 重排链表 中等

题目大意：
给定一个链表，按照前面拿一个，后面拿一个的顺序重新排列链表。

解题思路：
将后半段链表翻转，然后两段归并。

遇到的问题：
竟然在reverse链表的时候，忘记了将tail置为NULL了。

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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return;
        auto len = getLen(head);
        auto cur = head;
        for (int i = 0; i < (len-1)/2; ++i) {
            cur = cur->next;
        }
        auto right = reverse(cur->next);
        cur->next = NULL;
        cur = head;
        head = head->next;
        while (head != NULL || right != NULL) {
            if (right != NULL) {
                cur->next = right;
                right = right->next;
                cur = cur->next;
            }
            if (head != NULL) {
                cur->next = head;
                head = head->next;
                cur = cur->next;
            }
        }
        cur->next = NULL;
    }
    
    int getLen(ListNode *head) {
        int len = 0;
        while (head != NULL) {
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode *reverse(ListNode *head) {
        auto cur = head->next;
        auto ret = head;
        ret->next = NULL;
        while (cur != NULL) {
            auto tmp = cur;
            cur = cur->next;
            tmp->next = ret;
            ret = tmp;
        }
        return ret;
    }
};



