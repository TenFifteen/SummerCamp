/*
题目：28 % 通配符匹配 困难

题目大意：
给定一个字符串和一个通配符，进行匹配

解题思路：
动归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        int slen = strlen(s);
        int plen = strlen(p);
        vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= plen; ++i) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-1];
            }
        }
        for (int i = 1; i <= plen; ++i) {
            for (int j = 1; j <= slen; ++j) {
                if (p[i-1] == '*') {
                    dp[j][i] = dp[j-1][i-1] || dp[j-1][i];
                } else if (p[i-1] == '?' || p[i-1] == s[j-1]) {
                    dp[j][i] = dp[j-1][i-1];
                }
            }
        }
        return dp[slen][plen];
    }
};
