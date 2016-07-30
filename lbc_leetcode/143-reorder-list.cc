/*
题目大意：
给定一个单链表，将其元素按照1-》n -》2-》n-1-》3-》n-2.。。的次序排列。原地修改链表，
不可以申请额外空间，也不可以改变指针的内容，只可以改变指针。

解题思路：
将链表的后半部分翻转，然后进行链表的归并。

遇到的问题：
还是链表指针修改次序的问题，又搞了我好久。这东西真烦人，一定要够细心。

再次阅读：
感觉这种方法比较直观，没有太大问题。
但是代码还是稍微有些乱，可以参考一下下面的代码：
void reorderList(ListNode *head) {
    if (!head || !head->next) return;

    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;

    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }

    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)return;
        int len = 0;
        ListNode *tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            len++;
        }
        tmp = head;
        for(int i = 0; i < (len-1)/2; ++i){
            tmp = tmp->next;
        }
        ListNode *right = reverse(tmp->next);
        tmp->next = NULL;
        tmp = head;
        head = head->next;
        tmp->next = right;
        tmp = tmp->next;
        right = right->next;
        while(head != NULL || right != NULL){
            if(head != NULL){
                tmp->next = head;
                head = head->next;
                tmp = tmp->next;
            }
            if(right != NULL){
                tmp->next = right;
                right = right->next;
                tmp = tmp->next;
            }
        }
    }

    ListNode *reverse(ListNode *head){
        if(head == NULL)return head;
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
/*
第二次做：
还好吧，一开始把题意弄错了。最后还是出了一点点小错误。
链表，二叉树这种指针的问题，一定要细心啊。
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
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode * reverse(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *ret = NULL;
        while (head) {
            auto next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        return ret;
    }

public:
    void reorderList(ListNode* head) {
        int len = getLength(head);
        if (len < 3) return;

        ListNode *right = head;
        for (int i = 0; i < (len-1)/2; ++i) {
            right = right->next;
        }

        ListNode *tail = right;
        right = reverse(right->next);
        tail->next = NULL;

        while (right) {
            auto next = head->next;
            head->next = right;
            right = right->next;
            head->next->next = next;
            head = next;
        }
    }
};
/*
 * some good and easy question.
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

    int count(ListNode *head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }

public:
    void reorderList(ListNode* head) {
        int len = count(head);
        if (len < 3) return;

        ListNode *left = head;
        ListNode *right = head, *tail;
        for (int i = 0; i < len/2; ++i) {
            tail = right;
            right = right->next;
        }
        tail->next = NULL;
        right = reverse(right);

        ListNode tmp(0), *pre = &tmp;
        while (left || right) {
            if (left) {
                pre->next = left;
                pre = left;
                left = left->next;
            }
            if (right) {
                pre->next = right;
                pre = right;
                right = right->next;
            }
        }
    }
};
