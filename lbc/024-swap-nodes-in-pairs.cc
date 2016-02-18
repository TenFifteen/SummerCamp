/*
题目大意：
给定一个链表，让把所有相邻的数据交换过来。而且不可以交换值，只能交换指针；而且只可以遍历一遍。

解题思路：
直接找到两个元素，然后就交换之。但是要注意很多边界条件。

遇到的问题：
在返回的链表的最后一定要赋值为NULL。要不然就是死循环。

再次阅读：
这种题目一般都是直接考察写代码的能力的，要处理好各种边界条件。
当然了，在有可能的前提下，尽量的写出一手好代码应该是很有加分的。
所以可以参考一下下面这种简洁的写法：
ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode *ret = head->next;
        ListNode *cur = ret->next;
        ret->next = head;
        ListNode *last = head;
        head->next = NULL; // dead loop
        while(cur != NULL){
            if(cur->next == NULL){
                last->next = cur;
                break;
            }
            ListNode *tmp = cur->next->next;
            last->next = cur->next;
            last = last->next;
            last->next = cur;
            last = cur;
            last->next = NULL; //dead loop
            cur = tmp;
        }
        return ret;
    }
};
/*
第二次做：
感觉这次不太在状态啊，竟然有两次死循环出现了。看来今天做的已经是够多了，该歇歇了。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode prehead(0), *ret = &prehead;
        
        while (head) {
            if (head->next) {
                ListNode *next = head->next->next;
                
                ret->next = head->next;
                ret->next->next = head;
                ret = ret->next->next;
                head = next;
            } else {
                ret->next = head;
                return prehead.next;
            }
        }
        ret->next = NULL;
        
        return prehead.next;
    }
};