/*
题目大意：
给定k条排序的链表，将其合并。

解题思路：
堆

遇到的问题：
对于priority_queue的初始化还是不是很熟悉。
首先，如果pq要指定自己的排序方法的话，需要指定存储容器，也就是vector<T>，
另外其排序的方式跟sort接受的参数是不一样的，这里接受的是一个类型；而sort接受的是一个
对象。所以sort是sort(x.begin(), x.end(), Cmp())，
而pq是priority_queue<T, vector<T>, Cmp) pq
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
    class Cmp {
    public:
        bool operator() (ListNode *l, ListNode *r) {
            return l->val > r->val;
        }
    };
    
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode tmp(0), *ret = &tmp;
        
        priority_queue<ListNode *, vector<ListNode *>, Cmp> q;
        for (auto l : lists) {
            if (l) q.push(l);
        }
        
        while (q.size() > 0) {
            ListNode *cur = q.top();
            q.pop();
            
            ret->next = cur;
            ret = cur;
            
            if (cur->next) q.push(cur->next);
        }
        
        ret->next = NULL;
        return tmp.next;
    }
};


