/*
题目：25 % 合并k个排序链表 中等

题目大意：
给定k个链表，已经排序。
归并他们。

解题思路：
多路归并，用最小堆

遇到的问题：
对于set的比较函数的写法还有点不太熟。
*/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
     
    struct Cmp {
        bool operator() (ListNode *l, ListNode *r) {
            return l->val < r->val;
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        multiset<ListNode *, Cmp> heap;
        for (auto l : lists) {
            if (l != NULL) {
                heap.insert(l);
            }
        }
        ListNode *ret = NULL;
        ListNode *last = NULL;
        while (heap.size() > 0) {
            auto cur = *heap.begin();
            heap.erase(heap.find(cur));
            if (ret == NULL) {
                ret = cur;
                last = cur;
            } else {
                last->next = cur;
                last = cur;
            }
            cur = cur->next;
            if (cur != NULL) {
                heap.insert(cur);
            }
        }
        if (last != NULL) last->next = NULL;
        return ret;
    }
};



