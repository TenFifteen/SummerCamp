#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

struct Node{
    int row, col, val;
    Node(int r, int c, int v): row(r), col(c), val(v){}
};

void swap(vector<Node*> &A, int i, int j)
{
    Node *tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}
void minHeapify(vector<Node*> &A, int root, int n)
{
    int child = root * 2 + 1;
    if (child >= n) return;

    if (child+1 < n && A[child+1]->val < A[child]->val) ++child;
    if (A[child]->val < A[root]->val) {
        swap(A, child, root);
        minHeapify(A, child, n);
    }
}

void insertHeap(vector<Node*> &A, Node* node, int n)
{
    A[n-1] = node;
    int c = n - 1;
    int p = (c - 1) / 2;
    while (p >= 0 && A[p]->val > A[c]->val) {
        swap(A, c, p);
        c = p;
        p = (c - 1) / 2;
    }
}
/**
 ** @param matrix: a matrix of integers
 ** @param k: an integer
 ** @return: the kth smallest number in the matrix
 **/
int kthSmallest(vector<vector<int> > &matrix, int k) {
    // write your code here
    int m = matrix.size();
    if (m == 0) return INT_MIN;
    int n = matrix[0].size();

    vector<Node*> heap(n);
    for (int i = 0; i < n; ++i) {
         Node *node = new Node(0, i, matrix[0][i]);
         heap[i] = node;
    }
    for (int i = (n-2)/2; i >= 0; --i) {
         minHeapify(heap, i, n);
    }

    for (int i = 1; i < k; ++i) {
        swap(heap, 0, n-1);
        --n;
        minHeapify(heap, 0, n);
        if (heap[n]->row + 1 < n) {
            int val = matrix[heap[n]->row+1][heap[n]->col];
             insertHeap(heap, new Node(heap[n]->row+1, heap[n]->col, val), n+1);
             ++n;
        }
    }
    return heap[0]->val;
}

int main()
{

}
