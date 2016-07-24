/*
题目大意：
给一个排序的链表，元素有重复。删掉重复的元素。

解题思路：
用last指向最后一个非重复元素，与last相同的元素都要删掉。以此类推。

遇到的问题：
边界问题要好好处理，各种NULL的情况。

再次阅读：
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return NULL;
        ListNode *last = head;
        ListNode *cur = head->next;
        while(cur != NULL){
            while(cur != NULL && cur->val == last->val){
                ListNode *tmp = cur->next;
                delete cur;
                last->next = tmp;
                cur = tmp;
            }
            if(cur == NULL)break;
            last = cur;
            cur = cur->next;
        }
        return head;
    }
};
/*
第二次做：
这个跟上一题比就差远了，一分钟A掉
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;

        ListNode *ans = head, *tail = head;
        head = head->next;
        while (head) {
            if (head->val != tail->val) {
                tail->next = head;
                tail = head;
            }
            head = head->next;
        }

        tail->next = NULL;
        return ans;
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *ret = head, *tail = ret;
        head = head->next;
        while (head) {
            if (head->val != tail->val) {
                tail->next = head;
                tail = head;
            }
            head = head->next;
        }
        tail->next = NULL;
        return ret;
    }
};
