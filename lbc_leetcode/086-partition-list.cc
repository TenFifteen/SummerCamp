/*
题目大意：
给定一个链表，无序。给定一个整数x，将链表partition，比x小的放到左边；
剩下的放到右边。并且保持原来的顺序。

解题思路：
链表的题目。

遇到的问题：
一次通过。注意边界。

再次阅读：
感觉这道题也没啥困难，就是考验编码能力的。
本来以为之前的做法已经可以了。
结果在DISCUSS中竟然找到了下面这段代码，感觉真的是厉害极了：
ListNode *partition(ListNode *head, int x) {
    ListNode node1(0), node2(0);
    ListNode *p1 = &node1, *p2 = &node2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = node2.next;
    return node1.next;
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)return head;
        ListNode *left = NULL, *right = NULL;
        ListNode *left_tail = NULL, *right_tail = NULL;
        while(head){
            if(head->val < x){
                if(left == NULL){
                    left = head;
                    left_tail = left;
                }else{
                    left_tail->next = head;
                    left_tail = left_tail->next;
                }
                head = head->next;
            }else{
                if(right == NULL){
                    right = head;
                    right_tail = right;
                    head = head->next;
                    right_tail->next = NULL;
                }else{
                    right_tail->next = head;
                    right_tail = right_tail->next;
                    head = head->next;
                    right_tail->next = NULL;
                }
            }
        }
        if(left_tail == NULL)return right;
        left_tail->next = right;
        return left;
    }
};
/*
第二次做：
简单题，写的还可以。
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
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0), after(0);
        ListNode *bhead = &before, *ahead = &after;

        while (head) {
            if (head->val < x) {
                bhead->next = head;
                bhead = head;
            } else {
                ahead->next = head;
                ahead = head;
            }
            head = head->next;
        }

        bhead->next = after.next;
        ahead->next = NULL;

        return before.next;
    }
};
/*
 * some easy
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
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0), large(0), *small_pre = &small, *large_pre = &large;
        while (head) {
            if (head->val < x) {
                small_pre->next = head;
                small_pre = head;
            } else {
                large_pre->next = head;
                large_pre = head;
            }
            head = head->next;
        }

        large_pre->next = NULL;
        small_pre->next = large.next;
        return small.next;
    }
};
