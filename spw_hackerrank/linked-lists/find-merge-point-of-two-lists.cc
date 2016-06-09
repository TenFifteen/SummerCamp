/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
   int data;
   Node* next;
   }
   */
int len(Node *h) {
    int cnt = 0;
    while (h) {
        ++cnt;
        h = h->next;
    }

    return cnt;
}

int FindMergeNode(Node *headA, Node *headB)
{
    int lenA = len(headA), lenB = len(headB);

    Node *it1 = headA, *it2 = headB;
    if (lenB > lenA) swap(it1, it2);
    int diff = abs(lenA - lenB);

    while (diff--) it1 = it1->next;

    while (it1 != it2) {
        it1 = it1->next;
        it2 = it2->next;
    }

    return it1->data;
}

