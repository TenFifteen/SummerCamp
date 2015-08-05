/*
题目大意：
给定一个链表，链表中除了next指针，还有一个random指针，随机指向链表中的某个节点。
要求深复制一个链表出来。

解题思路：
先将每个节点double一下。
然后将random指针修改正确。
然后将链表一分为二。

遇到的问题：
各种指针修改次序问题，链表的确是容易搞错，一定要仔细的写关于链表的东西。
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)return NULL;
        RandomListNode *tmp = head;
        while(tmp != NULL){
            RandomListNode *next = tmp->next;
            tmp->next = new RandomListNode(tmp->label);
            tmp = tmp->next;
            tmp->next = next;
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp != NULL){
            if(tmp->random != NULL){
                tmp->next->random = tmp->random->next;
            }
            tmp = tmp->next->next;
        }
        RandomListNode *ret = head->next;
        RandomListNode *cur = ret;
        head->next = head->next->next;
        head = head->next;
        cur->next = NULL;
        while(head != NULL){
            cur->next = head->next;
            head->next = head->next->next;
            head = head->next;
            cur = cur->next;
            cur->next = NULL;
        }
        return ret;
    }
};