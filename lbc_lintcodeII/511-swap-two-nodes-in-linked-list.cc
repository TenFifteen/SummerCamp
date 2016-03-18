/*
题目大意：
给定一个链表，找到两个节点，分别是v1，和v2。并交换他们

解题思路：
主要是交换两个节点比较麻烦。见代码

遇到的问题：
没有太大问题。
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
    /**
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode tmp(0);
        tmp.next = head;
        ListNode *last = &tmp;
        
        ListNode *last1 = NULL, *last2 = NULL;
        while ((!last1 || !last2) && head) {
            if (head->val == v1) {
                last1 = last;
            } else if (head->val == v2) {
                last2 = last;
            }
            
            last = head;
            head = head->next;
        }
        
        if (last1 == NULL || last2 == NULL) return tmp.next;
        
        if (last1->next == last2) {
            last1->next = last2->next;
            last2->next = last1->next->next;
            last1->next->next = last2;
        } else if (last2->next == last1) {
            last2->next = last1->next;
            last1->next = last2->next->next;
            last2->next->next = last1;
        } else {
            ListNode *p1 = last1->next, *p2 = last2->next;
            last1->next = p1->next;
            last2->next = p2->next;
            
            p1->next = last2->next;
            last2->next = p1;
            
            p2->next = last1->next;
            last1->next = p2;
        }
        
        return tmp.next;
    }
};