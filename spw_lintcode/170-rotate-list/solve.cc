/**
 * Problem: Given a list, rotate the list to the right by k places, where k is non-negative.
 * Solve: use two pointer, test if the front->next == NULL
 * Tips: count if n great than k
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
        /**
         * @param head: the list
         * @param k: rotate to the right k places
         * @return: the list after rotation
         */
        ListNode *rotateRight(ListNode *head, int k) {
            int n = count(head);
            if (n == 0 || k % n == 0) return head;

            k %= n;

            ListNode *front = head;
            while (k--) front = front->next;

            ListNode *it = head;
            while (front->next) {
                front = front->next;
                it = it->next;
            }


            front->next = head;
            head = it->next;
            it->next = NULL;

            return head;
        }

        int count(ListNode *head) {
            int cnt = 0;
            while (head) {
                ++cnt;
                head = head->next;
            }

            return cnt;
        }
};
