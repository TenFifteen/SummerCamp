/*
题目大意：
给定一个字符串，问将字符串划分为各个子字符串都是回文子串的最小分割是多少？

解题思路：
动归。

遇到的问题：
一开始dp[0]的初始化错了。
*/
class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        if (s.size() < 2) return 0;
        
        vector<vector<bool>> P(s.size(), vector<bool>(s.size(), false));
        vector<int> dp(s.size()+1, INT_MAX);
        
        for (int i = 0; i < s.size(); ++i) P[i][i] = true;
        
        dp[0] = -1;
        dp[1] = 0;
        for (int i = 2; i <= s.size(); ++i) {
            dp[i] = dp[i-1]+1;
            for (int j = i-1; j >= 1; --j) {
                if (s[i-1] == s[j-1] && (j == i-1 || P[j][i-2])) P[j-1][i-1] = true;
                if (P[j-1][i-1]) {
                    dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        
        return dp[s.size()];
    }
};

