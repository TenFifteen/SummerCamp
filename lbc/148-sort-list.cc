/*
题目大意：
在nlogn时间复杂度内排序链表。

解题思路：
用归并排序。

遇到的问题：
还是没有能一次通过，不过这次只改了一次就通过了。

再次阅读：
思路没啥问题。其实也可以用快排。但是快排的速度不能保证。所以呢，还是归并比较合适。
另外就是可以通过先后指针的方式来计算链表的中点来加速。
也可以通过一次性计算出来长度，然后以后递归的时候都带上长度就行了。
这两种方式都可以加速。
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)return NULL;
        if(head->next == NULL)return head;
        int len = 0;
        ListNode *tmp = head;
        while(tmp != NULL){
            len++;
            tmp = tmp->next;
        }
        tmp = head;
        for(int i = 0; i < len/2-1; ++i){
            tmp = tmp->next;
        }
        ListNode *right = sortList(tmp->next);
        tmp->next = NULL;
        head = sortList(head);
        
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        while(head != NULL || right != NULL){
            if(right == NULL){
                cur->next = head;
                head = head->next;
                cur = cur->next;
                cur->next = NULL;
            }else if(head == NULL){
                cur->next = right;
                right = right->next;
                cur = cur->next;
                cur->next = NULL;
            }else{
                if(head->val < right->val){
                    if(ret == NULL){
                        ret = head;
                        cur = head;
                        head = head->next;
                        ret->next = NULL;
                    }else{
                        cur->next = head;
                        head = head->next;
                        cur = cur->next;
                        cur->next = NULL;
                    }
                }else{
                    if(ret == NULL){
                        ret = right;
                        cur = ret;
                        right = right->next;
                        ret->next = NULL;
                    }else{
                        cur->next = right;
                        right = right->next;
                        cur = cur->next;
                        cur->next = NULL;
                    }
                }
            }
        }
        return ret;
    }
};