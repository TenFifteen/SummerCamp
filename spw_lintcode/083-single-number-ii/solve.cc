/**
 * Problem: Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.
 * Solve: turn to zero when meet three distinct 1.
 * Tips: see comments below
 */
class Solution {
    public:
        /**
         * @param A : An integer array
         * @return : An integer
         */
        int singleNumberII(vector<int> &A) {
            int ones = 0, twos = 0;

            int n = A.size();
            for (int i = 0; i < n; ++i) {
                int aside = ones & A[i];
                ones ^= A[i];
                twos ^= aside;

                // 11 -> 00, import
                aside = ones & twos;
                ones ^= aside;
                twos ^= aside;
            }

            return ones;
        }
};
