/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    Node *dummy = new Node();
    Node *it = dummy, *tmp;

    while (headA || headB) {
        if (!headB || headA && headA->data < headB->data) {
            tmp = headA;
            headA = headA->next;
        } else {
            tmp = headB;
            headB = headB->next;
        }
        it->next = tmp;
        it = tmp;
    }

    return dummy->next;
}

