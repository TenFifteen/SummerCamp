/**
 * Problem: given an linked list, determine if it has a cycle in it
 * Solve: use two pointers
 * Tips: no
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *temp1 = head, *temp2 = head;

    while (temp1 && temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp2) {
            temp2 = temp2->next;
            if (temp2 == temp1) {
                return true;
            }
        }
    }

    return false;
}

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *it1 = head, *it2 = head;

            while (it2) {
                it1 = it1->next;
                it2 = it2->next;

                if (it2) it2 = it2->next;
                else return false;

                // must compare after it2 move
                if (it1 == it2) return true;
            }
            return false;

        }

};
