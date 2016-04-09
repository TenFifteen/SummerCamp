/**
 * Problem: Determine the number of bits required to flip
 *          if you want to convert integer n to integer m.
 * Solve: Use a variable to get the different bit and count them.
 * Tips: no
 */
class Solution {
    public:
        /**
         *@param a, b: Two integer
         *return: An integer
         */
        int bitSwapRequired(int a, int b) {
            int diff = a ^ b;

            int cnt = 0;
            while (diff) {
                ++cnt;
                diff &= diff - 1;
            }

            return cnt;
        }
};
