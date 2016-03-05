/*
题目大意：
给定一个链表，判断链表中是否存在环。

解题思路：
用两个指针，一个每次走两步，一个每次走一步。如果走两步的指针追上了走一步的指针，
说明有环。

遇到的问题：
经典问题，一次通过。
如果不考虑空间复杂度的要求的话，也可以将访问过的节点用hash存起来。

再次阅读：
经典老题，没有问题。
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)return false;
        ListNode *front = head->next;
        while(front != NULL){
            if(front == head)return true;
            if(front->next == NULL)return false;
            front = front->next->next;
            head = head->next;
        }
        return false;
    }
};
/*
第二次做：
经典老题了。没有什么问题。就是写的时候要小心点。
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        
        ListNode *front = head->next, *end = head;
        while (front && front != end) {
            front = front->next;
            if (front) front = front->next;
            end = end->next;
        }
        
        return front != NULL;
    }
};