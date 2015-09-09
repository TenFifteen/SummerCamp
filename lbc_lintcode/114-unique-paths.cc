/*
题目：36 % 不同的路径 容易

题目大意：
给定一个二维的矩阵，问从左上角到右下角共有多少条路径。

解题思路：
动归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<vector<int>> dp(m, vector<int>(n, 1));
        if (m == 0 || n == 0) return 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

