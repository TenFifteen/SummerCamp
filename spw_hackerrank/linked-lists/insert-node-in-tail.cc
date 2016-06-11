/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
    Node *now = new Node();
    now->data = data;
    now->next = NULL;

    if (head == NULL) return now;

    Node *tail = head;
    while (tail->next) tail = tail->next;

    tail->next = now;
    return head;
}

