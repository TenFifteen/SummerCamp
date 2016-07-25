/*
题目大意：
给定一个链表，排序，有重复元素。删掉所有的重复元素。

解题思路：
记录当前的指针和最后一个指针，然后遇到重复的元素就一直删，删到无重复为止。

遇到的问题：
还是各种边界问题。
不知道是长时间没写了还是就是不熟，总是不能一次通过。感觉边界很多很复杂。

再次阅读：
感觉题目没有什么难度，就是考察写代码的水平吧。
感觉之前的实现还是很啰嗦的。
下面这个是DISCUSS中比较好的解法：
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **runner = &head;

        if(!head || !head->next)return head;

        while(*runner)
        {
            if((*runner)->next && (*runner)->next->val == (*runner)->val)
            {
                ListNode *temp = *runner;
                while(temp && (*runner)->val == temp->val)
                    temp = temp->next;

                *runner = temp;
            }
            else
                runner = &((*runner)->next);
        }

        return head;
    }
};
通过观察可以发现，链表中，为了防止对头指针的各种判断问题，可以采用指向指针的这种形式。
但是这种题目，最好是问一下面试官，空间到底是否需要由我们来释放。
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
        if(head == NULL || head->next == NULL)return head;
        ListNode *ret = NULL, *cur = head->next, *last = head;
        ListNode *ret_tail = NULL;
        while(cur != NULL){
            if(cur->val == last->val){
                while(cur != NULL && cur->val == last->val){
                    ListNode *tmp = cur->next;
                    delete cur;
                    cur = tmp;
                }
                delete last;
                last = cur;
                if(cur == NULL)break;
                cur = cur->next;
            }else{
                if(ret == NULL){
                    ret = last;
                    ret_tail = last;
                }else{
                    ret_tail->next = last;
                }
                ret_tail = last;
                ret_tail->next = NULL;
                last = cur;
                cur = cur->next;
            }
        }
        if(last != NULL){
            if(ret_tail == NULL){
                return last;
            }else{
                ret_tail->next = last;
            }
        }
        return ret;
    }
};
/*
第二次做：
指针的问题果然是容易出错，这次又是有两个小地方出了些问题。不过还好，代码比之前好多了。
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
        ListNode prehead(0), *phead = &prehead, *last = head;

        int dup = 0;
        head = head->next;
        while (head) {
            if (head->val == last->val) {
                dup++;
            } else {
                if (!dup) {
                    phead->next = last;
                    phead = last;
                }
                last = head;
                dup = 0;
            }
            head = head->next;
        }

        if (!dup) {
            phead->next = last;
            phead = last;
        }
        phead->next = NULL;
        return prehead.next;
    }
};
/*
 * a little tedious
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

        ListNode tmp(0), *pre = &tmp;
        ListNode *last = head;
        head = head->next;
        bool dup = false;
        while (head) {
            if (head->val != last->val) {
                if (dup == false) {
                    pre->next = last;
                    pre = last;
                }
                last = head;
                dup = false;
            } else {
                dup = true;
            }
            head = head->next;
        }

        if (dup == false) {
            pre->next = last;
            pre = last;
        }
        pre->next = NULL;
        return tmp.next;
    }
};
