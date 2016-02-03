/*
题目大意：
给定一个单链表，将其所有的奇数位置的节点都放到偶数位置之后，但是还要保持原来的相对顺序。

解题思路：
遍历一遍，将链表拆开为奇数和偶数位置的，然后将偶数的放到奇数的后面就行了。

遇到的问题：
第一次写这种有preHead的指针，感觉还不错吧。

再次阅读：
是一个简单题，这种拆开然后再次拼接的方式挺好的。
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode tmp1(0), tmp2(0);
        ListNode *oHead = &tmp1, *eHead = &tmp2;
        ListNode *oCur = oHead, *eCur = eHead;
        
        bool odd = true;
        while (head) {
            ListNode *next = head->next;
            if (odd) {
                oCur->next = head;
                oCur = head;
            } else {
                eCur->next = head;
                eCur = head;
            }
            
            odd = !odd;
            head = next;
        }
        
        eCur->next = NULL;
        oCur->next = eHead->next;
        return oHead->next;
    }
};