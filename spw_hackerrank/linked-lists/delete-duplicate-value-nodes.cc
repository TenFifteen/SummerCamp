/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    Node *it = head;
    while (it) {
        Node *dup = it->next;
        while (dup && dup->data == it->data) {
            Node *tmp = dup;
            dup = dup->next;
            delete tmp;
        }
        // link the node
        it->next = dup;
        it = dup;
    }

    return head;
}

