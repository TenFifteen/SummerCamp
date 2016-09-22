/**
 * Problem: Given a singly linked list, group all odd nodes together
 *          followed by the even nodes. Please note here we are talking
 *          about the node number and not the value in the nodes.
 * Solve: two pointers
 * Tips: no
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
        ListNode* oddEvenList(ListNode* head) {
            ListNode *odd = new ListNode(0), *even = new ListNode(0);

            ListNode *it = head;
            ListNode *tail1 = odd, *tail2 = even;

            while (it) {
                tail1->next = it;
                tail1 = it;
                it = it->next;

                if (!it) break;

                tail2->next = it;
                tail2 = it;
                it = it->next;
            }

            tail1->next = even->next;
            tail2->next = NULL;
            return odd->next;
        }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode h1(0), h2(0);

        ListNode *tail1 = &h1, *tail2 = &h2;
        int cnt = 1;

        while (head) {
            if (cnt % 2 == 1) {
                tail1->next = head;
                tail1 = head;
            } else {
                tail2->next = head;
                tail2 = head;
            }

            ++cnt;
            head = head->next;
        }

        tail2->next = NULL;
        tail1->next = h2.next;

        return h1.next;
    }
};
