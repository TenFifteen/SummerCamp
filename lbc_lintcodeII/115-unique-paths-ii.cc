/*
题目大意：
给定一个二维的矩阵，其中1表示障碍物，0表示可以走。问从左上角的到右下角的路径数量是多少？

解题思路：
动归。

遇到的问题：
dp[0]忘记了初始化。。。
*/
class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) dp[0] = 0;
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] += dp[j-1];
            }
        }
        
        return dp[n-1];
    }
};