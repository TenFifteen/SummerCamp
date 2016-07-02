/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Problem: reverse nodes in a group with k nodes
 * Solve: First reverse all, then let k nodes be a group, reverse again
 * Tips: when (left = count % k) != 0, we should consider the left nodes.
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *new_head = NULL;

        int count = 0;
        while (temp) {
            ++count;
            // fetch pre
            ListNode *pre = temp;
            temp = temp->next;

            // add pre to new list
            pre->next = new_head;
            new_head = pre;
        }

        temp = new_head;
        head = NULL;

        int left = count % k;
        while (left--) {
            ListNode *pre = temp;
            temp = temp->next;

            pre->next = head;
            head = pre;
        }

        while (temp) {
            // fetch pre and pre->next
            ListNode *pre = temp;

            int tk = k;
            ListNode *tpre = NULL;
            while (tk--) {
                tpre = temp;
                temp = temp->next;
            }

            // add them to the new list
            tpre->next = head;
            head = pre;
        }

        return head;
    }
};

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy, *it = head;

        while (it) {
            int tk = k;
            ListNode *h = NULL, *tail = it;
            while (tk-- && it) {
                ListNode *now = it;
                it = it->next;

                now->next = h;
                h = now;
            }

// when it == null, tk minus one more, then >= 0 instead of 0
            if (tk >= 0) {
                while (h) {
                    ListNode *now = h;
                    h = h->next;

                    now->next = it;
                    it = now;
                }
                prev->next = it;
                break;
            } else {
                prev->next = h;
                tail->next = it;
                prev = tail;
            }
        }

        return dummy->next;
    }
};
