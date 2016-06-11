/**
 * Problem: print a linked list line by line
 * Solve: recursive.
 * Tips: no
 */
void Print(Node *head)
{
    if (head == NULL) {
        return;
    }

    cout << head->data << endl;
    Print(head->next);
}
