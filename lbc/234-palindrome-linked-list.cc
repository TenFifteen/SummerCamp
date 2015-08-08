/*
题目大意：
给定一个单链表。问其是否是回文的。

解题思路：
先计算出链表的长度。然后将后半部分放入stack中。然后再与前半部分比较。注意奇偶性。

遇到的问题：
一次通过。

不过题目中说是否可以用常数的空间。
我感觉是否可以将后半部分翻转呢？然后进行比较。比完了再翻回去？
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)return true;
        int len = 0;
        ListNode *tmp = head;
        while(tmp != NULL){
            len++;
            tmp = tmp->next;
        }
        tmp = head;
        for(int i = 0; i < (len+1)/2; ++i){
            tmp = tmp->next;
        }
        stack<int> s;
        while(tmp != NULL){
            s.push(tmp->val);
            tmp = tmp->next;
        }
        for(int i = 0; i < len/2; ++i){
            if(head->val != s.top())return false;
            s.pop();
            head = head->next;
        }
        return true;
    }
};