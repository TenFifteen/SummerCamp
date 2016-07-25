/**
 * Problem: Given a linked list, return the node where the cycle begins, return NULL is there
 *          no cycle.
 * Solve: temp1 takes one steps each time while temp2 takes twos steps.
 *        Suppose x is the distance from the begin to the start of the cycle, when they first meet
 *        Suppose the temp2 have taken b steps in the cycle and temp1 taken a steps.
 *        the we have the equation that:
 *        1. x + b = 2 * (x + a)
 *        2. b = a + n*r                   (r is the length of the cycle)
 *        then x = n*r - a;
 *        If we place one pointe in the start, and another one stay in place. They will eventually
 *        meet at the start of the cycle, because when one take x steps another on take n*r-a step.
 *        and a is the distance from the start of cycle to the first meet place
 * Tips: see below
 */
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *temp1 = head, *temp2 = head;
	int has_cycle = 0;
	while (temp2 != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 == NULL) return NULL;
		temp2 = temp2->next;

		if (temp2 == temp1) {
			has_cycle = 1;
			break;
		}
	}

	// determin if it has a cycle or we will get an run time exception
	if (!has_cycle) return NULL;

	temp2 = head;
	while (temp2 != temp1) {
		temp2 = temp2->next;
		temp1 = temp1->next;
	}

	return temp2;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *it1 = head, *it2 = head;

        while (it2) {
            it1 = it1->next;
            it2 = it2->next;

            if (it2) it2 = it2->next;
            else return NULL;

            if (it1 == it2) {
                it1 = head;
                while (it1 != it2) {
                    it1 = it1->next;
                    it2 = it2->next;
                }
                return it1;
            }
        }

        return NULL;
    }
};
