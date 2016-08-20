/*
题目大意：
给定一个字符串s，给以目标串t。在s的所有子序列中，有多少个t。

解题思路：
动态规划

遇到的问题：
竟然把s和t搞反了。

再次阅读：
直接用动归，是没有问题的。
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size())return 0;
        vector<vector<int>> dp(t.size()+1, vector<int>(s.size()+1, 0));
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == t[0]){
                dp[1][i+1] = dp[1][i]+1;
            }else{
                dp[1][i+1] = dp[1][i];
            }
        }
        for(int i = 1; i < t.size(); ++i){
            for(int j = i; j < s.size(); ++j){
                dp[i+1][j+1] = dp[i+1][j];
                if(t[i] == s[j]){
                    dp[i+1][j+1] += dp[i][j];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};
/*
第二次做：
动归。第一次初始条件搞错了。
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;

        vector<vector<int> > dp(s.size()+1, vector<int>(t.size()+1, 0));
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }

        return dp[s.size()][t.size()];
    }
};
/*
 * interesting
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[s.size()][t.size()];
    }
};
