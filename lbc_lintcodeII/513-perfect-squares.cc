/*
题目大意：
给定一个正整数，问将其表示成完全平方的和的完全平方的数量最少是多少？

解题思路：
动归。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        if (n < 1) return 0;
        
        vector<int> p;
        for (int i = 1; n/i >= i; ++i) {
            p.push_back(i*i);
        }
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < p.size(); ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j >= p[i]) dp[j] = min(dp[j], dp[j-p[i]]+1);
            }
        }
        
        return dp[n];
    }
};