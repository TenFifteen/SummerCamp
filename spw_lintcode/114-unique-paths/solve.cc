/**
 * Problem: A robot is located at the top-left corner
 *          of a m x n grid (marked 'Start' in the diagram below).
 *          The robot can only move either down or right at any
 *          point in time. The robot is trying to reach the
 *          bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * Solve: use a vector
 * Tips: the length of the dp vector && the initialization
 */
class Solution {
    public:
        /**
         * @param n, m: positive integer (1 <= n ,m <= 100)
         * @return an integer
         */
        int uniquePaths(int m, int n) {
            if (m == 0 || n == 0) return 0;

            vector<int> dp(n, 0);

            // the first column always be 1
            dp[0] = 1;
            for (int i = 0; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    dp[j] = dp[j-1] + dp[j];
                }
            }

            return dp[n-1];
        }
};

