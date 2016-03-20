/**
 * Problem: A happy number is a number defined by the following
 *          process: Starting with any positive integer, replace
 *          the number by the sum of the squares of its digits,
 *          and repeat the process until the number equals 1
 *          (where it will stay), or it loops endlessly in a cycle
 *          which does not include 1. Those numbers for which this
 *          process ends in 1 are happy numbers.
 * Solve: simulate the algorithm until the result run into 1 or 4
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param n an integer
         * @return true if this is a happy number or false
         */
        bool isHappy(int n) {
            // Write your code here
            while (n != 1) {

                int sum = 0;
                while (n) {
                    int digit = n % 10;
                    sum += digit * digit;
                    n /= 10;
                }

                if (sum == 4) return false;
                n = sum;
            }

            return true;
        }
};
