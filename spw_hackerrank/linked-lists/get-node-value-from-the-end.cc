/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    Node *it1 = head, *it2 = head;

    while (positionFromTail--) it1 = it1->next;

    while (it1->next) {
        it1 = it1->next;
        it2 = it2->next;
    }

    return it2->data;
}

