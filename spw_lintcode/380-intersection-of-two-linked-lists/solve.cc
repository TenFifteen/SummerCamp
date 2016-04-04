/**
 * Problem: Write a program to find the node at which the intersection
 *          of two singly linked lists begins.
 * Solve: find the difference of length
 * Tips: see comments below
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
    int countLink(ListNode *h) {
        int count = 0;
        while (h) {
            h = h->next;
            count++;
        }

        return count;
    }
    public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = countLink(headA);
        int lenB = countLink(headB);

        ListNode *h1, *h2;
        int diff;
        if (lenA > lenB) {
            diff = lenA - lenB;

            h1 = headA, h2 = headB;
            while (diff--) h1 = h1->next;
        } else {
            diff = lenB - lenA;

            h1 = headB, h2 = headA;
            while (diff--) h1 = h1->next;
        }

        // make sure h1 and h2 are all valid
        while (h1 && h2 && h1 != h2) {
            h1 = h1->next;
            h2 = h2->next;
        }

        // determine which condition to break
        if (h1 == h2) return h1;

        return NULL;
    }
};
