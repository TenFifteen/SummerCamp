/*
题目大意：
实现正则表达式。正则表达式支持. 和 *。

解题思路：
采用动归。主要是在当前模式串为*的时候的情况需要特殊考虑。
另外，由于空串是等于空串的。所以需要将空串考虑到动归的过程中。

遇到的问题：
一开始觉得比较难，但是使劲想了想，动归解起来还可以。所以，一定不能畏惧动归。

再次阅读：
这种题目，感觉动归还是正解啊。
看了一下DISCUSS的解法，基本大家最喜欢的还是动归。所以这里就不再多写了。
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
/*
第二次做：
这次虽然直接就知道用动归了，但是还是写了一下子没写出来，还是早上起来又调试出来的，主要是哪个*的匹配条件比较多，还有初始条件
也是需要仔细斟酌的。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= p.size(); ++i) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-1] || dp[0][i-2];
            }
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j-1] == '*') {
                    if (((p[j-2] == '.' || p[j-2] == s[i-1]) && (dp[i-1][j-1] || dp[i-1][j]))
                    || dp[i][j-1]
                    || dp[i][j-2]) {
                        dp[i][j] = true;
                    }
                } else if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        
        return dp[s.size()][p.size()];
    }
};