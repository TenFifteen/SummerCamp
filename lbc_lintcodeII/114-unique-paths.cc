/*
题目大意：
给定一个矩阵，问从左上角走到右下角有多少种方案。

解题思路：
动归。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m < 1 || n < 1) return 0;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j-1];
            }
        }
        
        return dp[n-1];
    }
};
