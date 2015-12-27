#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given an integer array, heapify it to a min-heap array.
 * Solve:no
 * Tips: no
 */
void minHeapify(vector<int> &A, int root, int n) {
    int child = root * 2 + 1;
    if (child >= n) return;

    if (child + 1 < n && A[child+1] < A[child]) {
        child++;
    }

    if (A[child] < A[root]) {
        int tmp = A[child];
        A[child] = A[root];
        A[root] = tmp;
        minHeapify(A, child, n);
    }
}

/**
 * @param A: Given an integer array
 * @return: void
 */
void heapify(vector<int> &A) {
    int n = A.size();
    if (n == 0) return;
    // write your code here
    // notice: (n - 1 - 1)
    for (int i = (n-2)/2; i >= 0; --i){
        minHeapify(A, i, n);
    }
}
