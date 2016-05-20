/*
题目大意：
求两个链表的交点。

解题思路：
见代码。

遇到的问题：
没有。
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
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        int lenA = getLength(headA), lenB = getLength(headB);
        
        if (lenA < lenB) for (int i = 0; i < lenB-lenA; ++i) headB = headB->next;
        if (lenB < lenA) for (int i = 0; i < lenA-lenB; ++i) headA = headA->next;
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};
