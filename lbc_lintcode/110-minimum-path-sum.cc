/*
题目：34 % 最小路径和 容易

题目大意：
给定一个二维的矩阵，从左上角到右下角的所有路径中，最小的路径和是多少

解题思路：
动归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < grid[0].size(); ++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

