/**
 * Problem: Reverse digits of an integer. Returns 0 when the
 *          reversed integer overflows (signed 32-bit integer).
 * Solve: reverse
 * Tips: handle the overflow
 */
class Solution {
    public:
        /**
         ** @param n the integer to be reversed
         ** @return the reversed integer
         **/
        int reverseInteger(int n) {
            bool sign = true;
            if (n < 0) {
                sign = false;
                n = -n;
            }

            int ans = 0;
            while (n) {
                int digit = n % 10;

                int tmp = ans * 10 + digit;
                if (tmp / 10 != ans) return 0;
                ans = tmp;

                n = n / 10;
            }

            if (!sign) ans = -ans;
            return ans;

        }

};
