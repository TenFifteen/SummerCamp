/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Problem:Implement a function to check if a linked list is a palindrome.
 * Solve: reverse half of the linked list
 * Tips: see comments below.
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        int count = 0;

        ListNode* it = head;
        while (it) {
            ++count;
            it = it->next;
        }

        int mid = count / 2;

        ListNode *h1 = NULL;
        while (mid--) {
            ListNode *now = head;
            head = head->next;

            now->next = h1;
            h1 = now;
        }

        ListNode *h2 = head;
        // count is odd
        if (count % 2 == 1 && h2) h2 = h2->next;

        while (h1 && h2) {
            if (h1->val != h2->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }

        return h1 == h2;
    }
};
