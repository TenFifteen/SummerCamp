/*
题目大意：
给一个链表，将链表右移k位。

解题思路：
用两个指针，前后之间差k个。当后一个到达最后的时候，就是应该移动到前边去的那段。

遇到的问题：
一开始并没有想用两个指针。看到题目提示里竟然有，所以就这么用了。
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tmp = head;
        int len = 0;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        if(len <= 1)return head;
        k %= len;
        if(k == 0)return head;
        ListNode *front = head;
        ListNode *end = head;
        for(int i = 0; i < k; ++i){
            front = front->next;
        }
        ListNode *last = NULL;
        while(front->next != NULL){
            front = front->next;
            last = end;
            end = end->next;
        }
        front->next = head;
        last = end->next;
        end->next = NULL;
        return last;
    }
};