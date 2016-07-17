#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoList(ListNode *l1, ListNode* l2)
{
    if (l1 == NULL) return l2;
    // warning: the else is necessary, or the time will exceed
    else if (l2 == NULL) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }
}

ListNode *mergeTwoList1(ListNode *l1, ListNode* l2)
{
    ListNode *fake = new ListNode(0);
    ListNode *now = fake;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            now->next = l1;
            l1 = l1->next;
        } else {
            now->next = l2;
            l2 = l2->next;
        }
        now = now->next;
    }
    if (l1 == NULL) {
        now->next = l2;
    } else {
        now->next = l1;
    }
    now = fake->next;
    delete fake;
    return now;
}

/**
 * Problem: Merge k sorted linked lists and return it as one sorted list.
 *          Analyze and describe its complexity.
 * Solve: use merge two sorted list function and merge them one by one.
 * Tips: n*2^x + 2*n*2^(x-1) + ... = n*2^x + n*2^x + ... = x*n*2^x = nklg(k)(2^x = k)
 */
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if (lists.empty()) return NULL;
    int len = lists.size();
    while (len > 0) {
        for (int i = 0; i < len/2; ++i) {
            lists[i] = mergeTwoList(lists[i], lists[len-1-i]);
        }
        len = (len + 1) / 2;
    }
    return lists.front();
}


int main()
{
    vector<ListNode *> lists;

}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp{
    bool operator() (const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, cmp> q;

            ListNode *head = new ListNode(0);
            ListNode *it = head;

            for (int i = 0; i < lists.size(); ++i)
                if (lists[i])
                    q.push(lists[i]);

            while (!q.empty()) {
                ListNode *now = q.top();
                q.pop();

                it->next = now;
                it = now;

                if (now->next) q.push(now->next);
            }
            it->next = NULL;

            return head->next;
        }
};
