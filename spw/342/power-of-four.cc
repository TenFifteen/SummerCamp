/**
 * Problem: Given an integer (signed 32 bits), write a
 *          function to check whether it is a power of 4.
 *          judge without loop.
 * Solve: judge one bit first then use mask to judge the
 *        position.
 * Tips: 0
 */
class Solution {
    public:
        bool isPowerOfFour(int num) {
            static int mask = 0x55555555;

            if (num == 0) return false;

            if ((num & num-1) == 0) {
                if ((num & mask) != 0) {
                    return true;
                }
            }

            return false;
        }
};
