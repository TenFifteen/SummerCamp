/*
题目大意：
有两个链表，表示两个整数（非负）。然后这个链表是反正表示的，也就是说，前边的是地位的，后边的是高位的。

解题思路：
正常的整数相加都是从低位往高位加。所以直接将两个链表从头到尾加起来产生一个新的链表就是答案。
时间复杂度n，空间复杂度n。

遇到的问题：
这道题主要是审题问题，一看到倒序的，我就想到了翻转链表，然后就走入了误区，将两个链表分别翻转后相加，然后再
将结果翻转。所以还是审题问题。

考察点：
链表操作。

再次阅读：
之前的解法已经是最优的了。
不过这次看完题之后，还是忍不住去翻转链表了，没有注意到链表本身就已经是倒序的了。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        //l1 = reverse(l1);
        //l2 = reverse(l2);
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        int last = 0;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                last += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                last += l2->val;
                l2 = l2->next;
            }
            if(ret == NULL){
                ret = new ListNode(last % 10);
                cur = ret;
            }else{
                cur->next = new ListNode(last % 10);
                cur = cur->next;
            }
            last /= 10;
        }
        if(last != 0){
            cur->next = new ListNode(last);
        }
        //return reverse(ret);
        return ret;
    }
    
    ListNode* reverse(ListNode *head){
        if(head == NULL){
            return NULL;
        }
        ListNode *cur = head;
        ListNode *next = head->next;
        cur->next = NULL;
        while(next != NULL){
            ListNode *tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }
};
/*
第二次做：
没有太大问题，只是指针稍微有两个初始化的小细节。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead = ListNode(0), *head = &preHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }
            
            head->next = new ListNode(carry % 10);
            head = head->next;
            carry /= 10;
        }
        if (carry != 0) {
            head->next = new ListNode(carry);
        }
        return preHead.next;
    }
};