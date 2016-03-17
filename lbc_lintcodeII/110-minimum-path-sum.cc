/*
题目大意：
给定一个二维矩阵，问从左上角到右下角的最小路径是啥？

解题思路：
动归。

遇到的问题：
dp[0]一开始忘记了初始化了。
*/
class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        
        return dp[n-1];
    }
};
