/*
题目大意：
通配符匹配

解题思路：
动态规划。注意题目中的**是可以连着使用的。

遇到的问题：
**竟然可以连着使用。。。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> tmp(p.size()+1, false);
        vector<vector<bool>> dp(s.size()+1, tmp);
        dp[0][0] = true;
        for(int i = 0; i < p.size(); ++i){
            if(p[i] != '*')break;
            dp[0][i+1] = true;
        }
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 1; j <= p.size(); ++j){
                if(p[j-1] == '*'){
                    if(dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1]){
                        dp[i][j] = true;
                    }
                }else if(p[j-1] == '?' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};