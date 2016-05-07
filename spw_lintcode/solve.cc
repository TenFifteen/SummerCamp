/**
 * Problem: Given two 32-bit numbers, N and M, and two bit positions,
 *          i and j. Write a method to set all bits between i and j in
 *          N equal to M (e g , M becomes a substring of N located at i and starting at j)
 * Solve: construct the mask(use (1 << (x+1))-1)
 * Tips: see comments below.
 */
class Solution {
    public:
        /**
         *@param n, m: Two integer
         *@param i, j: Two bit positions
         *return: An integer
         */
        int updateBits(int n, int m, int i, int j) {
            if (i > j) {
                int tmp = i;
                i = j;
                j = tmp;
            }

            int mask;
            if (j == 31) {
                // if j==31, then if we shift 32 bits, it will be overflow
                mask = ((1 << i) - 1) ^ (-1);
            } else {
                // in proper we will shift j+1, but the left mask needn't
                mask = ((1 << i) - 1) ^ ((1 << j+1) - 1);
            }

            n &= ~mask;
            n |= m << i;

            return n;
        }
};
