/**
 * Problem: Given a positive integer n, break it into the sum of
 *          at least two positive integers and maximize the product
 *          of those integers. Return the maximum product you can get.
 *
 *          For example, given n = 2, return 1 (2 = 1 + 1); given n = 10,
 *          return 36 (10 = 3 + 3 + 4).
 * Solve: divide the number averagely as possible as we can and remember
 *        the product.
 * Tips: no
 */
class Solution {
    public:
        int integerBreak(int n) {
            int num = n;

            long ans = 0;
            for (int k = 2; k <= n; ++k) {
                int fac = num / k;
                int re = num - fac * k;
                re = k - re + 1;

                long long now = 1;
                for (int i = 1; i <= k; ++i) {
                    if (i == re) {
                        fac++;

                    }

                    now *= fac;

                }

                if (now >= ans) ans = now;
                else break;

            }

            return ans;

        }

};
