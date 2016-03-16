/*
题目大意：
对链表进行排序。

解题思路：
归并排序。

遇到的问题：
没有。
*/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
    int count(ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode tmp(0), *ret = &tmp;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ret->next = l1;
                ret = l1;
                l1 = l1->next;
            } else {
                ret->next = l2;
                ret = l2;
                l2 = l2->next;
            }
        }
        
        if (l1) ret->next = l1;
        if (l2) ret->next = l2;
        return tmp.next;
    }
    
    ListNode *mySort(ListNode *head, int n) {
        if (n < 2) return head;
        
        ListNode *ret = head;
        for (int i = 0; i < (n-1)/2; ++i) {
            head = head->next;
        }
        
        ListNode *right = mySort(head->next, n/2);
        head->next = NULL;
        head = mySort(ret, n-n/2);
        
        return merge(head, right);
    }
    
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        int n = count(head);
        return mySort(head, n);
    }
};


