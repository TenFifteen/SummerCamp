/*
题目：28 % 硬币排成线 III 困难

题目大意：
给定一个数组，表示一排硬币的价值。
两个人分别取硬币，每次每个人可以从任意一端取一个硬币。
问先手是否可以必胜？

解题思路：
动归。

遇到的问题：
没有问题。
不过题目中说，如果硬币的数目是偶数，是否可以优化到n。我还是没想出来。
*/
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        if (n < 2) return true;
        vector<vector<int>> sum(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            sum[i][i] = values[i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                sum[j][j+i] = sum[j][j+i-1] + values[j+i];
            }
        }
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = values[i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                dp[j][j+i] = values[j] + (sum[j+1][j+i]-dp[j+1][j+i]);
                dp[j][j+i] = max(dp[j][j+i], values[j+i] + (sum[j][j+i-1]-dp[j][j+i-1]));
            }
        }
        
        return dp[0][n-1] > sum[0][n-1]-dp[0][n-1];
    }
};
