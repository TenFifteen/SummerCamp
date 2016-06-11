/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    if (position == 0) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    } else {
        Node *it = head;
        while (--position)
            it = it->next;
        Node *tmp = it->next;
        it->next = tmp->next;
        delete tmp;
    }

    return head;
}

