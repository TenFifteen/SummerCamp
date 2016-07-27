/**
 ** Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    struct ListNode *next;
};

int countList(struct ListNode *head) {
	int count = 0;
	while (head) {
		++count;
		head = head->next;
	}
	return count;
}

/**
 * Problem: write a program to find the node at which the intersection of two single linked
 *          lists begins.
 * Solve: similar way with the solution to kth node from the end.
 * Tips: 1A
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = countList(headA);
	int lenB = countList(headB);

	struct ListNode *tempA = headA;
	struct ListNode *tempB = headB;
	int diff = lenA - lenB;
	if (lenA > lenB) {
		while (diff--) {
			tempA = tempA->next;
		}
	} else if (lenA < lenB) {
		diff = -diff;
		while (diff--) {
			tempB = tempB->next;
		}
	}

	while (tempA) {
		if (tempA == tempB) return tempA;
		tempA = tempA->next;
		tempB = tempB->next;
	}

	return NULL;
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
    int getLen(ListNode *h) {
        int cnt = 0;
        while (h) {
            h = h->next;
            ++cnt;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLen(headA), len2 = getLen(headB);
        if (len1 < len2) swap(headA, headB);

        int dlen = abs(len1 - len2);
        ListNode *it1 = headA, *it2 = headB;
        while (dlen--) it1 = it1->next;

        while (it1 && it2 && it1 != it2) {
            it1 = it1->next;
            it2 = it2->next;
        }

        return it1 == it2 ? it1 : NULL;
    }
};
