/**
 * Problem: Given 2*n + 1 numbers, every numbers occurs twice except one, find it.
 * Solve: XOR
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A: Array of integers.
         * return: The single number.
         */
        int singleNumber(vector<int> &A) {
            int sum = 0;
            int n = A.size();
            for (int i = 0; i < n; ++i) {
                sum ^= A[i];
            }

            return sum;
        }
};

