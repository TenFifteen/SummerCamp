/*
题目大意：
给定那个房子，可以涂成三种颜色。给出每个房子涂成每种颜色的价格。
连续的房子不可以涂成相同的颜色。问最后代价最小是多少？

解题思路：
动归。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        int n = costs.size();
        
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0] = costs[0];
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + costs[i][j];
            }
        }
        
        int ans = dp[n-1][0];
        ans = min(ans, dp[n-1][1]);
        ans = min(ans, dp[n-1][2]);
        return ans;
    }
};