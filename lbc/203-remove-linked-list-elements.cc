/*
题目大意：
给定给一个单链表，删掉所有等于val的节点

解题思路：
另外建一个链表，将需要保存的节点放进去，其他的删掉

遇到的问题：
一次通过。
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