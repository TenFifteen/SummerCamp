/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    Node *h = NULL, *tmp;
    while (head) {
        tmp = head;
        head = head->next;

        tmp->next = h;
        h = tmp;
    }

    return h;
}

