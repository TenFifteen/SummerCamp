/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    Node *it1 = head, *it2 = head;

    while (it2) {
        it1 = it1->next;
        it2 = it2->next;

        if (it2)  it2 = it2->next;
        else  return false;

        if (it1 == it2) return true;
    }

    return false;
}

/**
 * A wrong answer
 */
bool has_cycle(Node* head) {
    if (head == NULL) return false;

    Node *it1 = head, *it2 = head;
    do {
        it1 = it1->next;
        // should detect if t2 == NULL
        it2 = it2->next;

        if (it2 == NULL) return false;
        else it2 = it2->next;
    } while (it1 != it2);

    // false break when t2 == NULL
    return true;
}
