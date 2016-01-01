#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/**
 * Problem: Merge k sorted lists and return it as on sorted list.
 * Solve: use heap where the elements is pair<ListNode*, int> to keep the position
 *        of the element in the lists.
 * Tips: see comments below.
 */
class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
};

void swap(vector<pair<ListNode*, int> > &A, int i, int j)
{
    pair<ListNode*, int> tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}
void minHeapify(vector<pair<ListNode*, int> > &A, int root, int n)
{
    int child = root * 2 + 1;
    if (child >= n) return;

    if (child+1 < n && A[child+1].first->val < A[child].first->val) ++child;
    if (A[child].first->val < A[root].first->val) {
        swap(A, child, root);
        minHeapify(A, child, n);
    }
}
void insertHeap(vector<pair<ListNode*, int> > &A, pair<ListNode*, int> node, int n)
{
    A[n-1] = node;
    int c = n - 1;
    int p = (c - 1) / 2;
    while (p >= 0 && A[p].first->val > A[c].first->val) {
        swap(A, c, p);
        c = p;
        p = (c - 1) / 2;
    }
}
/**
 * @param lists: a list of ListNode
 * @return: The head of one sorted list.
 */
ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    int n = lists.size();
    if (n == 0) return head->next;

    vector<pair<ListNode*, int> > heap(n);

    int pos = 0;
    for (int i = 0; i < n; ++i) {
        // 1. warn!! Skip the NULL list.
        if (lists[i] != NULL) {
            heap[pos++] = make_pair(lists[i], i);
            lists[i] = lists[i]->next;
        }
    }
    n = pos;

    for (int i = (n-2)/2; i >= 0; --i) {
        minHeapify(heap, i, n);
    }

    // 2. warn!! When the n is 0 return directly.
    while (n > 0) {
        // pop the node
        swap(heap, 0, n-1);
        tail->next = heap[n-1].first;
        tail = tail->next;

        // shrink and adjust the heap
        --n;
        minHeapify(heap, 0, n);

        // fetch a node from the pop node list
        int pos = heap[n].second;
        if (lists[pos] != NULL) {
            insertHeap(heap, make_pair(lists[pos], pos), n+1);
            lists[pos] = lists[pos]->next;
            ++n;
        }

        //3. warn!! When left only one list, append it to the main list
        //don't forget to the add the element in the heap.
        if (n == 1) {
            tail->next = heap[0].first;
            tail = tail->next;
            tail->next = lists[heap[0].second];
            break;
        }
    }
    return head->next;
}

int main()
{
    vector<ListNode *> lists;
    ListNode *now = new ListNode(2);
    lists.push_back(now);
    now = new ListNode(-1);
    lists.push_back(now);
    lists.push_back(NULL);

    ListNode * result = mergeKLists(lists);
    while (result) {
        cout << result->val << "  " ;
        result = result->next;
    }
    cout << "NULL" << endl;
    return 0;
}
