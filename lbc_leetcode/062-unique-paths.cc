/*
题目大意：
给一个二维矩阵，问从左上角走到右下角，一共有多少种走法。

解题思路：
动态规划。

遇到的问题：
一次通过。

再次阅读:
题目很简单，就是一个最简单的动归。
然后看了一眼之前写的代码。这是唯一一个我觉得比DISCUSS中的代码好的。空间也已经优化。
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> ans(m,1);
        for(int i = 0; i < n-1; ++i){
            for(int j = 1; j < m; ++j){
                ans[j] += ans[j-1];
            }
        }
        return ans[m-1];
    }
};
/*
第二次做：
简单动归。不过，这次的代码开始考虑边界条件了，是个好事。
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        vector<int> ans(m, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                ans[j] += ans[j-1];
            }
        }
        return ans[m-1];
    }
};
/*
 * very easy dp
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
