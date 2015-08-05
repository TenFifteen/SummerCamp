/*
题目大意：
给定一个链表，求是否有环。如果有环，求出环的起点。

解题思路：
与141同。但是两个指针遇到了之后，只需要将其中一个置为head，然后两个指针同时走，每次一步。
再次相遇的时候就是起点了。
原因是：
假设从head到环的距离是m，环的长度是n。
那么当end刚进入环的时候，front在环中走了m。
front要追上end，需要n-m。所以两者相遇的时候，end距离起点是m。

遇到的问题：
自己想不出来，还是看了别人的思路。
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)return NULL;
        ListNode *front = head, *end = head;
        while(front != NULL){
            if(front->next == NULL)return NULL;
            front = front->next->next;
            end = end->next;
            if(front == end){
                end = head;
                while(end != front){
                    front = front->next;
                    end = end->next;
                }
                return front;
            }
        }
        return NULL;
    }
};