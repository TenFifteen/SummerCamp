/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Problem: Given a singly linked list, determine if it is a palindrome.
 * Solve: reverse half of the list, then compare.
 * Tips: care about reverse
 */
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if (head == NULL) return true;

            ListNode *h = head;
            int count = 0;

            while (h) {
                h = h->next;
                ++count;
            }

            int t = count / 2;
            for (int i = 0; i < t; ++i) {
                ListNode *tmp = head;
                head = head->next;

                tmp->next = h;
                h = tmp;// watch out
            }

            if (count % 2 == 1) head = head->next;

            while (h && head) {
                if (h->val != head->val) return false;
                h = h->next;
                head = head->next;
            }
            return true;
        }
};

class Solution {
public:
    int listLen(ListNode *h) {
        int cnt = 0;
        while (h) {
            h = h->next;
            ++cnt;
        }
        return cnt;
    }

    bool isPalindrome(ListNode* head) {
        int len = listLen(head);
        if (len < 2) return true;

        ListNode *h = NULL;
        int half = len / 2;

        while (half--) {
            ListNode *now = head;
            head = head->next;

            now->next = h;
            h = now;
        }

        if (len & 0x1) head = head->next;

        while (h && head) {
            if (h->val != head->val) return false;

            h = h->next;
            head = head->next;
        }

        return true;
    }
};
