/*
题目大意：
给定两个字符串，定义三种操作，增加一个字符，删掉一个字符，更改一个字符。
求出两个字符串的最小编辑距离。

解题思路：
动态规划。对于dp[i][j]，word1[i] == word2[j]，那么久等于dp[i-1][j-1]
要不然就等于dp[i-1][j], dp[i][j-1], dp[i-1][j-1]三个的最小值加1

遇到的问题：
一次通过。

再次阅读：
动归没有问题。
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0)return word2.size();
        if(word2.size() == 0)return word1.size();
        vector<int> tmp(word2.size(), INT_MAX);
        vector<vector<int>> dp(word1.size(), tmp);
        if(word1[0] == word2[0]){
            dp[0][0] = 0;
        }else{
            dp[0][0] = 1;
        }
        for(int i = 1; i < word2.size(); ++i){
            if(word2[i] == word1[0]){
                dp[0][i] = i;
            }else{
                dp[0][i] = dp[0][i-1] + 1;
            }
        }
        for(int i = 1; i < word1.size(); ++i){
            if(word1[i] == word2[0]){
                dp[i][0] = i;
            }else{
                dp[i][0] = dp[i-1][0] + 1;
            }
        }
        for(int i = 1; i < word1.size(); ++i){
            for(int j = 1; j < word2.size(); ++j){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int tmp = min(dp[i-1][j], dp[i][j-1]);
                    tmp = min(tmp, dp[i-1][j-1]);
                    dp[i][j] = tmp+1;
                }
            }
        }
        return dp[word1.size()-1][word2.size()-1];
    }
};
/*
第二次做：
简单动归。没有问题，这次代码稍微简化了一点点。
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i = 1; i <= word1.size(); ++i) dp[i][0] = i;
        for (int i = 1; i <= word2.size(); ++i) dp[0][i] = i;
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};