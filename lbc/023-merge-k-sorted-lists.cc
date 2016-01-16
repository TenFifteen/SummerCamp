/*
题目大意：
给k个排序的链表，然后进行归并排序。

解题思路：
就是k路归并问题。将多路链表放到小堆中。
时间复杂度就是n（log（k））,空间复杂度是k

遇到的问题：
对于priority_queue的自定义排序函数的使用要熟练。

再次阅读：
K路归并问题，经典问题，虽然没有什么疑问，但是在DISCUSS中看到了这么一种解法（两两归并）
然后我就查了一下K路归并排序的经典求解方式，就是用堆来做的。
然后如果总元素大小为N，则复杂度为Nlogk
如果用下面这种方式呢，假设链表长度都相同，则每个链表的长度为n=N/k
然后k-1次的归并花费的时间分别是：2n,3n,...,kn
然后将其求和为(2n+kn)*(k-1)/2 ~= k*k*n = k*N
所以这种方式的理论时间应该是要长一些的。

另外，K路归并的应用场景一般是外排序，一般是内容无法在内存中放下的，所以用这种堆结构
是在所难免的，而这种两两归并的方式就显然不可以了。

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
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
    struct Cmp{
        bool operator() (ListNode *left, ListNode *right){
            return left->val >= right->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] != NULL)pq.push(lists[i]);
        }
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        while(!pq.empty()){
            ListNode *head = pq.top();
            pq.pop();
            if(ret == NULL){
                ret = head;
                cur = head;
            }else{
                cur->next = head;
                cur = head;
            }
            if(head->next != NULL)pq.push(head->next);
        }
        return ret;
    }
};