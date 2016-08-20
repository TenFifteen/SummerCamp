/*
题目大意：
给定一个单链表。用插入排序进行排序。

解题思路：
直接插入排序就是了。

遇到的问题：
链表操作经过上一道题的联系，感觉这道题错误少了很多。
但是还是没能一次通过。

再次阅读：
我感觉吧，所有跟链表有关的代码，最好都是使用一个prehead，这样的话，就可以不用
单独处理头结点需要改变的情况了。如下：
public ListNode insertionSortList(ListNode head) {
        if( head == null ){
            return head;
        }

        ListNode helper = new ListNode(0); //new starter of the sorted list
        ListNode cur = head; //the node will be inserted
        ListNode pre = helper; //insert node between pre and pre.next
        ListNode next = null; //the next node will be inserted
        //not the end of input list
        while( cur != null ){
            next = cur.next;
            //find the right place to insert
            while( pre.next != null && pre.next.val < cur.val ){
                pre = pre.next;
            }
            //insert between pre and pre.next
            cur.next = pre.next;
            pre.next = cur;
            pre = helper;
            cur = next;
        }

        return helper.next;
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)return head;
        ListNode *ret = head;
        head = head->next;
        ret->next = NULL;
        while(head != NULL){
            ListNode *next = head->next;
            if(head->val <= ret->val){
                head->next = ret;
                ret = head;
            }else{
                ListNode *tmp = ret;
                ListNode *last = ret;
                while(tmp != NULL && tmp->val < head->val){
                    last = tmp;
                    tmp = tmp->next;
                }
                if(tmp == NULL){
                    last->next = head;
                    head->next = NULL;
                }else{
                    last->next = head;
                    head->next = tmp;
                }
            }
            head = next;
        }
        return ret;
    }
};
/*
第二次做：
还不错。
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode tmp(0), *ret = &tmp;

        while (head) {
            auto next = head->next;

            ListNode *cur = ret->next, *tail = ret;
            while (cur && cur->val < head->val) {
                tail = cur;
                cur = cur->next;
            }
            tail->next = head;
            head->next = cur;

            head = next;
        }

        return ret->next;
    }
};
/*
 * easy
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *ret = head;
        head = head->next;
        ret->next = NULL;

        while (head) {
            ListNode *next = head->next;

            if (head->val <= ret->val) {
                head->next = ret;
                ret = head;
            } else {
                ListNode *cur = ret, *tail;
                while (cur && cur->val < head->val) {
                    tail = cur;
                    cur = cur->next;
                }
                tail->next = head;
                head->next = cur;
            }
            head = next;
        }
        return ret;
    }
};
