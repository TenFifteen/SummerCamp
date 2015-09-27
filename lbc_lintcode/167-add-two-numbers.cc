/*
题目：21 % 两个链表的和 容易

题目大意：
用一个链表来表示一个整数各位的倒序，然后求两个链表的和

解题思路：
直接加

遇到的问题：
忘了加最后last的判断了。
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *ret = NULL, *cur = NULL;
        int last = 0;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                last += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                last += l2->val;
                l2 = l2->next;
            }
            if (ret == NULL) {
                ret = new ListNode(last % 10);
                cur = ret;
            } else {
                cur->next = new ListNode(last % 10);
                cur = cur->next;
            }
            last /= 10;
        }
        if (last != 0) {
            cur->next = new ListNode(last);
        }
        return ret;
    }
};
