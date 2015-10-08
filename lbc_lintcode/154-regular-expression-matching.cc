/*
题目：24 % 正则表达式匹配 困难

题目大意：
给定一个字符串和一个正则表达式，问是否匹配

解题思路：
动态规划。

遇到的问题：
各种边界条件。
感觉这道题目的确是有很多细节需要注意。
*/
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        int slen = strlen(s);
        int plen = strlen(p);
        vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
        dp[0][0] = true;
        if (p[0] == '*') return false; // start with *
        for (int i = 1; i <= plen; ++i) { // deal with "" and "a*b*"
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        for (int i = 1; i <= slen; ++i) {
            for (int j = 1; j <= plen; ++j) {
                if (p[j-1] == '*') {
                    if (dp[i][j-2] || dp[i][j-1]) {
                        dp[i][j] = true;
                    } else if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i-1][j];
                    }
                } else if (p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[slen][plen];
    }
};
