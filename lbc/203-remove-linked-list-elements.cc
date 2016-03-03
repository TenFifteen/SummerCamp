/*
题目大意：
给定给一个单链表，删掉所有等于val的节点

解题思路：
另外建一个链表，将需要保存的节点放进去，其他的删掉

遇到的问题：
一次通过。

再次阅读：
一看这道题就知道，至少这样写肯定是比较麻烦的。
应该加一个假的prehead，或者取一个head的地址，来避免单独判断头指针的情形。
ListNode *removeElements(ListNode *head, int val)
{
    ListNode **list = &head;

    while (*list != nullptr)
    {
        if ((*list)->val == val)
        {
            *list = (*list)->next;
        }
        else
        {
            list = &(*list)->next;
        }
    }

    return head;
}
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        if(head == NULL)return ret;
        while(head != NULL){
            if(head->val != val){
                if(ret == NULL){
                    ret = head;
                    cur = ret;
                }else{
                    cur->next = head;
                    cur = cur->next;
                }
                head = head->next;
                cur->next = NULL;
            }else{
                auto tmp = head->next;
                delete head;
                head = tmp;
            }
        }
        return ret;
    }
};
/*
第二次做：
虽然简单，但是还是出了点问题，ret-》next忘了置为NULL了。
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode tmp(0), *ret = &tmp;
        
        while (head) {
            if (head->val != val) {
                ret->next = head;
                ret = head;
            }
            head = head->next;
        }
        ret->next = NULL;
        
        return tmp.next;
    }
};