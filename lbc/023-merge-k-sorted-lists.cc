/*
题目大意：
给k个排序的链表，然后进行归并排序。

解题思路：
就是k路归并问题。将多路链表放到小堆中。
时间复杂度就是n（log（k））,空间复杂度是k

遇到的问题：
对于priority_queue的自定义排序函数的使用要熟练。
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
    struct Cmp{
        bool operator() (ListNode *left, ListNode *right){
            return left->val >= right->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] != NULL)pq.push(lists[i]);
        }
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        while(!pq.empty()){
            ListNode *head = pq.top();
            pq.pop();
            if(ret == NULL){
                ret = head;
                cur = head;
            }else{
                cur->next = head;
                cur = head;
            }
            if(head->next != NULL)pq.push(head->next);
        }
        return ret;
    }
};