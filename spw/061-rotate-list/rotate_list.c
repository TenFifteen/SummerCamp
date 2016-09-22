/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     struct ListNode *next;
 ** };
 **/
/**
 * Problem: Given a list, rotate the list to the right by k places, where k is non-negative.
 * Solve: first get the lenght of the list, then let k mod len
 * Tips: see comment below
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head) return head;

    struct ListNode* now = head;
    int len = 0;
    while (now) {
        now = now->next;
        len++;
    }
    // notice that key may bigger than len
    if (k % len == 0) return head;


    now = head;
    k = k % len;
    while (k--) {
        now = now->next;
    }
    struct ListNode *pre = head;
    while (now->next) {
        pre = pre->next;
        now = now->next;
    }

    struct ListNode* temp_head = pre->next;
    now->next = head;
    pre->next = NULL;

    return temp_head;
}

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
        int length(ListNode *h) {
            int cnt = 0;
            while (h) {
                ++cnt;
                h = h->next;
            }

            return cnt;
        }
        ListNode* rotateRight(ListNode* head, int k) {
            int n = length(head);
            if (n == 0) return head;

            k %= n;

            ListNode *dummy = new ListNode(0);
            dummy->next = head;

            ListNode *front = dummy, *tail = dummy;
            while (k--) tail = tail->next;

            while (tail->next) {
                tail = tail->next;
                front = front->next;
            }

            tail->next = dummy->next;
            head = front->next;
            front->next = NULL;

            delete dummy;
            return head;
        }
};

class Solution {
    int cntList(ListNode *h) {
        int cnt = 0;
        while (h) {
            h = h->next;
            ++cnt;
        }

        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        int cnt = cntList(head);
        k = cnt - k % cnt;

        ListNode left(0);
        ListNode *tail1 = &left;
        tail1->next = head;
        while (k--) {
            tail1 = tail1->next;
        }

        ListNode right(0);
        ListNode *tail2 = &right;
        tail2->next = tail1->next;
        while (tail2->next) {
            tail2 = tail2->next;
        }

        tail2->next = left.next;
        tail1->next = NULL;

        return right.next;
    }
};
