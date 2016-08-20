/**
 * Problem: Write a program to find the n-th ugly number.
 * Solve: (discuss board)use three pointers to remember
 *        every possible answer. We can use induction to
 *        prove the newly generated number 'now' must be
 *        bigger than the number 'before'.
 *        Because we use ++ every time, we will not skip
 *        any possible ugly number.
 * Tips: no
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;

        vector<int> nums(n);
        nums[0] = 1;

        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < n; ++i) {
            int now = min(nums[t2]*2, min(nums[t3]*3, nums[t5]*5));
            nums[i] = now;

            if (now % 2 == 0) t2++;
            if (now % 3 == 0) t3++;
            if (now % 5 == 0) t5++;
        }

        return nums[n-1];
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        int two = 0, three = 0, five = 0;

        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            dp[i] = min(dp[two]*2, min(dp[three]*3, dp[five]*5));

            if (dp[i] % 2 == 0) ++two;
            if (dp[i] % 3 == 0) ++three;
            if (dp[i] % 5 == 0) ++five;
        }

        return dp[n-1];
    }
};
