/*
题目：36 % 带环链表 II 困难

题目大意：
给定一个链表，其中可能会有环，如果有环，求出环起始的位置。

解题思路：
假设没有环的部分的长度是m，环长n。相遇是距离环起点x:
则：2(m+x) = m+n+x
所以m = n-x
也就是说环中剩下的长度等于m的长度。
所以这时候让其中一个回到head，两个指针同时走，每次一个步长，则再次相遇时就是环的入口。

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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (head == NULL) return NULL;
        auto end = head;
        auto front = head;
        while (front != NULL) {
            front = front->next;
            if (front == NULL) return NULL;
            front = front->next;
            end = end->next;
            if (front == end) break;
        }
        if (front == NULL) return NULL;
        end = head;
        while (end != front) {
            front = front->next;
            end = end->next;
        }
        return end;
    }
};



