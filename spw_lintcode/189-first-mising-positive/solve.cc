/**
 * Problem: Given an unsorted integer array, find the first missing positive integer.
 *          That is find the first missing number in 1...n
 * Solve: place every number between 1 and n to the right place.
 * Tips: 1. The condition to stop: it's not the i place you place right number but the
 *          place you will place A[i] just the same with A[i]. Otherwise, the while loop
 *          will never break.
 *          and this condition implies that A[i]-1 has placed the right number.
 *          because A[A[i]-1] = A[i]
 */
class Solution {
    public:
        /**
         * @param A: a vector of integers
         * @return: an integer
         */
        int firstMissingPositive(vector<int> A) {
            int n = A.size();

            for (int i = 0; i < n; ++i) {
                while (A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i]) {
                    swap(A[i], A[A[i]-1]);
                }
            }

            for (int i = 0; i < n; ++i)
                if (A[i] != i+1)
                    return i+1;

            return n+1;
        }
};
