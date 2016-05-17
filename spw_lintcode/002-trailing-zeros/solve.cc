/**
 * Problem: Write an algorithm which computes the number of trailing zeros in n factorial.
 * Solve: find the factor of 5
 * Tips: no
 */
class Solution {
    public:
        // param n : description of n
        // return: description of return
        long long trailingZeros(long long n) {
            long long ans = 0;

            while (n) {
                n /= 5;
                ans += n;
            }

            return ans;
        }
};

