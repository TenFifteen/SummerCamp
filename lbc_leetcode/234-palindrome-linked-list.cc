/*
题目大意：
给定一个单链表。问其是否是回文的。

解题思路：
先计算出链表的长度。然后将后半部分放入stack中。然后再与前半部分比较。注意奇偶性。

遇到的问题：
一次通过。

不过题目中说是否可以用常数的空间。
我感觉是否可以将后半部分翻转呢？然后进行比较。比完了再翻回去？

再次阅读：
是的，上面已经说得不错了。大多数人的常数空间就是通过翻转链表做的。
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
/*
第二次做：
如果按照题目要求，不能使用额外空间的话，那么只能这样做了吧。
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
private:
    int getLenght(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* reverse(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *ret = head;
        head = head->next;
        ret->next = NULL;
        while (head) {
            auto next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        return ret;
    }

public:
    bool isPalindrome(ListNode* head) {
        int len = getLenght(head);
        if (len < 2) return true;

        ListNode *right = head;
        for (int i = 0; i < (len-1)/2; ++i) {
            right = right->next;
        }

        ListNode *last = right;
        right = reverse(right->next);
        last->next = NULL;

        bool isP = true;
        ListNode *L = head, *R = right;
        while (L && R) {
            if (L->val != R->val) {
                isP = false;
                break;
            }
            L = L->next;
            R = R->next;
        }

        last->next = reverse(right);
        return isP;
    }
};
/*
 * ok
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
private:
    ListNode *reverse(ListNode *head) {
        ListNode *ret = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        return ret;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *front = head, *end = head, *last = end;
        while (front) {
            front = front->next;
            last = end;
            end = end->next;
            if (front) front = front->next;
        }

        last->next = NULL;
        ListNode *right = reverse(end);
        bool isP = true;
        ListNode *left = head;
        while (left && right) {
            if (left->val != right->val) {
                isP = false;
                break;
            }
            left = left->next;
            right = right->next;
        }

        last->next = reverse(right);
        return isP;
    }
};
