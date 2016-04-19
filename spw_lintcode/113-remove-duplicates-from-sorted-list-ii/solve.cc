/**
 * Problem: Given a sorted linked list, delete all nodes that have
 *          duplicate numbers, leaving only distinct numbers from the original list.
 * Solve: pointers to ponintes
 * Tips: when to update the pointer to pointer
 */
#include <iostream>
#include <vector>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
};

ListNode * deleteDuplicates(ListNode *head) {
    ListNode *it = head, **p = &head;

    while (it) {
        bool del = false;
        while (it->next && it->next->val == it->val) {
            it = it->next;
            del = true;
        }

        if (del) {
            it = it->next;
        } else {
            *p = it;
            // this update must go ahead of it->next
            // or there will be nothing influnce
            p = &it->next;
            it = it->next;
        }
    }
    *p = NULL;

    return head;

}

int main()
{
    int arr[] = {1,2,3,3,4,4,5};
    int len = 7;
    ListNode *head = new ListNode(0), *it = head;

    for (int i = 0; i < len; ++i) {
        it->next = new ListNode(arr[i]);
        it = it->next;
    }

    it->next = NULL;
    it = head;
    while (it) {
        cout << it->val << "->";
        it = it->next;
    }
    cout << "NULL" << endl;

    head = deleteDuplicates(head);
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;

    return 0;
}
