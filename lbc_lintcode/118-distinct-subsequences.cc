/*
题目：30 % 不同的子序列 中等

题目大意：
给定两个字符串，S的所有子序列中有多少个等于T

解题思路：
动态规划

遇到的问题：
人家说要优化空间，但是我感觉我现在对于这部分还不是很熟悉，虽然知道怎么优化，就是代码写不利索。
这一块一定要多加练习。
*/
class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        if (S.size() < T.size()) return 0;
        vector<vector<int>> dp(S.size(), vector<int>(T.size(), 0));
        if (S[0] == T[0]) dp[0][0] = 1;
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == T[0]) {
                dp[i][0] = dp[i-1][0] + 1;
            } else {
                dp[i][0] = dp[i-1][0];
            }
        }
        
        for (int i = 1; i < S.size(); ++i) {
            for (int j = 1; j < T.size(); ++j) {
                dp[i][j] = dp[i-1][j];
                if (S[i] == T[j]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[S.size()-1][T.size()-1];
    }
};

