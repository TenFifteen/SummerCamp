/*
题目大意：
实现正则表达式。正则表达式支持. 和 *。

解题思路：
采用动归。主要是在当前模式串为*的时候的情况需要特殊考虑。
另外，由于空串是等于空串的。所以需要将空串考虑到动归的过程中。

遇到的问题：
一开始觉得比较难，但是使劲想了想，动归解起来还可以。所以，一定不能畏惧动归。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p)return true;
        vector<bool> tmp(p.size() + 1, false);
        vector<vector<bool>> dp(s.size() + 1, tmp);
        dp[0][0] = true;
        for(int i = 1; i <= s.size(); ++i){
            dp[i][0] = false;
        }
        for(int i = 0; i <= s.size(); ++i){
            for(int j = 1; j <= p.size(); ++j){
                if(i == 0){
                    if(p[j-1] != '*'){
                        dp[i][j] = false;
                    }else{
                        dp[i][j] = dp[i][j-2];
                    }
                }
                else if(p[j-1] == '*'){
                    if(((p[j-2] == '.' || p[j-2] == s[i-1]) && dp[i-1][j]) || dp[i][j-2]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else if(p[j-1] == '.' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};