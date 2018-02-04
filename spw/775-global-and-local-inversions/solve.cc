/*
 * Problem: We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.
 *          The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].
 *          The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].
 *          Return true if and only if the number of global inversions is equal to the number of local inversions.
 * Solve: local must be global, then swap the local we must get a sorted array
 * Tips: no
 */
class Solution {
    public:
        bool isIdealPermutation(vector<int>& A) {
            int n = A.size();
            if (n < 3) return true;


            for (int i = 1; i < n; ++i) {
                if (A[i] < A[i-1]) {
                    swap(A[i], A[i-1]);
                    ++i;
                }
            }

            for (int i = 1; i < n; ++i) {
                if (A[i] < A[i-1])
                    return false;
            }

            return true;
        }
};
