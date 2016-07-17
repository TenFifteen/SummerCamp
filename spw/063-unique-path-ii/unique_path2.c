/**
 * Problme: unique path with obstacle
 * Sovle: simple dp
 * Tips: see comments below
 */
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int dp[100][100];

    int i, j;
    dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
    for (i = 1; i < obstacleGridRowSize; ++i) {
        dp[i][0] = obstacleGrid[i][0] || !dp[i-1][0] ? 0 : 1;
    }
    for (j = 1; j < obstacleGridColSize; ++j) {
        dp[0][j] = obstacleGrid[0][j] || !dp[0][j-1] ? 0 : 1;
    }
    for (i = 1; i < obstacleGridRowSize; ++i) {
        for (j = 1; j < obstacleGridColSize; ++j) {
            dp[i][j] = 0;
            if (obstacleGrid[i][j] == 0) {
                if (obstacleGrid[i-1][j] == 0)
                    dp[i][j] += dp[i-1][j];
                if (obstacleGrid[i][j-1] == 0)
                    dp[i][j] += dp[i][j-1];
            }
        }
    }
    return dp[obstacleGridRowSize-1][obstacleGridColSize-1];
}

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            if (m < 1) return 0;
            int n = obstacleGrid[0].size();


            vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

            dp[1][0] = 1;

            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (obstacleGrid[i-1][j-1] == 0)
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }

            return dp[m][n];
        }
};
