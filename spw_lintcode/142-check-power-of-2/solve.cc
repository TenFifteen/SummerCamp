/**
 * Problem: Using O(1) time to check whether an integer n is a power of 2.
 * Solve: bit operation.
 * Tips: 1. operator precedence. == greater than &
 *       2. all 0 and all 1s should be judge additional.
 */
class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        if (n == 0 || n == INT_MIN) return false;

        return (n & n - 1) == 0;
    }
};
