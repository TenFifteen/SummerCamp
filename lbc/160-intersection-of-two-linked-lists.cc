/*
题目大意：
给定两个链表，如果两个链表有交叉，求出交叉点。

解题思路：
先计算出两个链表的长度，然后让长的先走多出来的那段。然后两个链表同时走，如果相同，
就是交叉点，要不然走到最后都没有，就是没有交叉。

遇到的问题：
经典的问题，一次通过。

再次阅读：
首先，原来的代码有待改进，计算链表长度可以拿出来形成一个函数了。
然后呢，这个方法应该是比较成熟的方法了，但是在DISCUSS中有一种不需要计算长度的算法，
实在是巧妙极了。其实如果两个链表长度相同，只需要走一遍就行了。如果不同，每个链表也最多走两遍。
比之前那种无论如何都是走两遍的方式稍微好了一点，主要是提供了另一种思路。
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }

    return p1;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *tmp = headA;
        while(tmp != NULL){
            tmp = tmp->next;
            lenA++;
        }
        tmp = headB;
        while(tmp != NULL){
            tmp = tmp->next;
            lenB++;
        }
        if(lenA > lenB){
            for(int i = 0; i < lenA-lenB; ++i){
                headA = headA->next;
            }
        }else{
            for(int i = 0; i < lenB-lenA; ++i){
                headB = headB->next;
            }
        }
        while(headA != NULL){
            if(headA == headB)return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};