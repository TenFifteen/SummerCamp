/**
 * Problem: Given a m x n grid filled with non-negative numbers, find a path from top
 *          left to bottom right which minimizes the sum of all numbers along its path.
 * Solve: simple dp
 * Tips: the initialization.
 *        1. m*n matrix, think aside i = 0 or j = 0
 *        2. (m+1)*(n+1) matrix, all is set to INT_MAX but dp[0][1] or dp[1][0]
 */
class Solution {
    public:
        /**
         * @param grid: a list of lists of integers.
         * @return: An integer, minimizes the sum of all numbers along its path
         */
        int minPathSum(vector<vector<int> > &grid) {
            int m = grid.size();
            if (m == 0) return 0;

            int n = grid[0].size();

            vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

            dp[0][1] = dp[1][0] = 0;
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
                }
            }

            return dp[m][n];
        }
};
