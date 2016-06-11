/*
  Insert Node at a given position in a linked list
  head can be NULL
  First element in the linked list is at position 0
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node *now = new Node();
    now->data = data;
    now->next = NULL;

    if (position == 0) {
        now->next = head;
        return now;
    } else {
        Node *it = head;
        while (--position) {
            it = it->next;
        }
        now->next = it->next;
        it->next = now;
        return head;
    }
}

