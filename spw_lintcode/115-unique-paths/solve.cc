/**
 * Problem: Follow up for "Unique Paths":
 *          Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *          An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * Solve: dp use one vector
 * Tips: the initialize of dp[0]
 */
class Solution {
    public:
        /**
         * @param obstacleGrid: A list of lists of integers
         * @return: An integer
         */
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            int m = obstacleGrid.size();
            if (m == 0) return 0;
            int n = obstacleGrid[0].size();

            vector<int> dp(n, 0);

            dp[0] = 1;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j == 0) {
                        // this must be cooperate with dp[0] = 1
                        dp[j] = obstacleGrid[i][j] == 0 && dp[j] == 1 ? 1 : 0;
                    } else {
                        if (obstacleGrid[i][j] == 0) {
                            dp[j] = dp[j] + dp[j-1];
                        } else {
                            dp[j] = 0;
                        }
                    }
                }
            }

            return dp[n-1];
        }
};
