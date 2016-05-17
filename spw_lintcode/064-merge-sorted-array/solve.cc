/**
 * Problem: Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * Solve: from end to the begin.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A: sorted integer array A which has m elements,
         *           but size of A is m+n
         * @param B: sorted integer array B which has n elements
         * @return: void
         */
        void mergeSortedArray(int A[], int m, int B[], int n) {
            int index = m+n-1;

            int i = m - 1, j = n - 1;
            while (i >= 0 || j >= 0) {
                if (j < 0 ) return;

                if (i < 0) A[index--] = B[j--];
                else {
                    if (A[i] < B[j]) {
                        A[index--] = B[j--];
                    } else {
                        A[index--] = A[i--];
                    }
                }
            }
        }
};
