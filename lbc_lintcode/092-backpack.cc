/*
题目：19 % 背包问题 中等

题目大意：
给定一个背包，一系列有大小的物品。
问最多可以拿多少物品

解题思路：
简单的01背包，简单的动归。

遇到的问题：
没有判断是否所有物品的和都没有背包容量大，所以会超时。
*/
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int sum = getSum(A);
        if (sum <= m) return sum;
        vector<vector<int>> dp(A.size()+1, vector<int>(m+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= A.size(); ++j) {
                dp[j][i] = dp[j-1][i];
                if (i >= A[j-1]) {
                    dp[j][i] = max(dp[j][i], dp[j-1][i-A[j-1]] + A[j-1]);
                }
            }
        }
        return dp[A.size()][m];
    }
    
    int getSum(vector<int> &A) {
        int ans = 0;
        for (auto a : A) {
            ans += a;
        }
        return ans;
    }
};
