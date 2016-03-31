#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Divide two integers without using multiplication, division and mod operator.
 *          If it is overflow, return 2147483647
 * Solve: use bit shifting
 * Tips: 1. When divisor == 0;
 *       2. When divisor == INT_MIN && divisor == -1 return INT_MAX
 *       3. Use long long instead of int: INT_MAX 2, when we shift 2 to exceed INT_MAX,
 *          it will be overflow
 */
class Solution {
    public:
        /**
         * @param dividend the dividend
         * @param divisor the divisor
         * @return the result
         */
        int divide(int dividend, int divisor) {
            if (divisor == 0) return INT_MAX;

            if (dividend == INT_MIN && divisor == -1) {
                return INT_MAX;
            }

            bool sign = true;
            long long m = dividend;
            long long n = divisor;
            if (m < 0) {
                m = -m;
                sign = !sign;
            }
            if (n < 0) {
                n = -n;
                sign = !sign;
            }

            if (n == 1) return sign ? m : -m;

            int factor = 0;
            while (m >= n) {
                int f = 1;
                long long p = n;

                while (m >= (p << 1)) {
                    f <<= 1;
                    p <<= 1;
                }

                m -= p;
                factor += f;
            }

            return sign ? factor : -factor;
        }
};


