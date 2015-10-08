/*
题目：27 % 复制带随机指针的链表 中等

题目大意：
给定一个链表， 链表中除了有执行下一个节点的指针，还有一个随机的指针。
复制该链表一份出来。

解题思路：
先将链表原地复制一遍，然后分拆开。

遇到的问题：
没有问题。
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (head == NULL) return NULL;
        auto cur = head;
        while (cur != NULL) {
            auto next = cur->next;
            auto newptr = new RandomListNode(cur->label);
            newptr->next = next;
            cur->next = newptr;
            newptr->random = cur->random;
            cur = next;
        }
        cur = head;
        while (cur != NULL) {
            cur = cur->next;
            if(cur->random != NULL) cur->random = cur->random->next;
            cur = cur->next;
        }
        auto ret = head->next;
        head->next = ret->next;
        cur = ret;
        head = head->next;
        while (head != NULL) {
            auto next = head->next;
            head = next->next;
            cur->next = next;
            cur = next;
        }
        cur->next = NULL;
        return ret;
    }
};
