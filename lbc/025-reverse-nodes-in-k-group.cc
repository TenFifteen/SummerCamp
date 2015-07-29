/*
题目大意：
给一个链表，给一个数字k。以k个一组，进行翻转。

解题思路：
找出k个一组的链表，进行reverse。然后把每块连起来。

遇到的问题：
这种程序都是各种边界比较烦人，一定要注意处理了所有的边界情况。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2 || head == NULL)return head;
        ListNode *last = NULL;
        ListNode *ret = NULL;
        while(true){
            ListNode *khead = head;
            bool ok = true;
            for(int i = 0; i < k ; ++i){
                if(head != NULL){
                    if(i == k-1){
                        ListNode *tmp = head;
                        head = head->next;
                        tmp->next = NULL;
                    }else{
                        head = head->next;
                    }
                }else{
                    ok = false;
                    break;
                }
            }
            if(ok){
                ListNode *tmp = khead;
                khead = reverse(khead);
                if(ret == NULL){
                    ret = khead;
                    last = tmp;
                }else{
                    last->next = khead;
                    last = tmp;
                }
            }
            else{
                if(ret == NULL)return khead;
                last->next = khead;
                break;
            }
        }
        return ret;
    }
    
    ListNode *reverse(ListNode *head){
        ListNode *last = head;
        head = head->next;
        last->next = NULL;
        while(head != NULL){
            ListNode *tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }
        return last;
    }
};