/**
 * Problem: You are a professional robber planning to rob houses along a street.
 * Solve: dp
 * Tips: can optimal to O(1) space.
 */
class Solution {
    public:
        /**
         * @param A: An array of non-negative integers.
         * return: The maximum amount of money you can rob tonight
         */
        long long houseRobber(vector<int> A) {
            int n = A.size();
            if (n == 0) return 0;

            vector<long long> dp(n+1, 0);
            dp[0] = 0;
            dp[1] = A[0];

            int ans = 0;
            for (int i = 2; i <= n; ++i) {
                dp[i] = max(dp[i-1], A[i-1] + dp[i-2]);
            }

            return dp[n];
        }
};
