/*
题目大意：
给定一个链表，排序，有重复元素。删掉所有的重复元素。

解题思路：
记录当前的指针和最后一个指针，然后遇到重复的元素就一直删，删到无重复为止。

遇到的问题：
还是各种边界问题。
不知道是长时间没写了还是就是不熟，总是不能一次通过。感觉边界很多很复杂。
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode *ret = NULL, *cur = head->next, *last = head;
        ListNode *ret_tail = NULL;
        while(cur != NULL){
            if(cur->val == last->val){
                while(cur != NULL && cur->val == last->val){
                    ListNode *tmp = cur->next;
                    delete cur;
                    cur = tmp;
                }
                delete last;
                last = cur;
                if(cur == NULL)break;
                cur = cur->next;
            }else{
                if(ret == NULL){
                    ret = last;
                    ret_tail = last;
                }else{
                    ret_tail->next = last;
                }
                ret_tail = last;
                ret_tail->next = NULL;
                last = cur;
                cur = cur->next;
            }
        }
        if(last != NULL){
            if(ret_tail == NULL){
                return last;
            }else{
                ret_tail->next = last;
            }
        }
        return ret;
    }
};