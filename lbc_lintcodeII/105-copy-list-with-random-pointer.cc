/*
题目大意：
复制带有随机指针的链表。

解题思路：
见代码。

遇到的问题：
链表操作过程中有好几处bug。而且一开始还把第二步和第三步放到了一起，出了bug。
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
        
        //double list
        RandomListNode tmp(0), *tail = &tmp;
        while (head) {
            RandomListNode *next = head->next;
            tail->next = head;
            tail = head;
            tail->next = new RandomListNode(tail->label);
            tail = tail->next;
            head = next;
        }
        
        //random pointer
        head = tmp.next;
        while (head) {
            if (head->random) {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        
        //split list
        head = tmp.next;
        tail = &tmp;
        while (head) {
            tail->next = head->next;
            tail = tail->next;
            head->next = tail->next;
            head = head->next;
        }
        
        return tmp.next;
    }
};