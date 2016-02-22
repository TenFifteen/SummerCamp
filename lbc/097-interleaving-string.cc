/*
题目大意：
给两个字符串，和一个目标串。问是否可以由前两个字符串的交织来形成第三个串？

解题思路：
动态规划。当前的目标串去掉最后一个匹配字母与两个字符串进行匹配。

遇到的问题：
一开始边界弄错了一点。

再次阅读：
直接使用动归即可。
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())return false;
        if(s1 == ""){
            if(s2 == s3)return true;
            return false;
        }
        if(s2 == ""){
            if(s1 == s3)return true;
            return false;
        }
        vector<bool> tmp(s2.size()+1, false);
        vector<vector<bool>> dp(s1.size()+1, tmp);
        for(int i = 0; i <= s1.size(); ++i){
            for(int j = 0; j <= s2.size(); ++j){
                if(i == 0 && j == 0){
                    dp[0][0] = true;
                    continue;
                }
                if(i == 0){
                    dp[i][j] = s2.substr(0,j) == s3.substr(0,j);
                    continue;
                }else if(j == 0){
                    dp[i][j] = s1.substr(0,i) == s3.substr(0,i);
                    continue;
                }
                if(s1[i-1] == s3[i+j-1] && dp[i-1][j])dp[i][j] = true;
                if(s2[j-1] == s3[i+j-1] && dp[i][j-1])dp[i][j] = true;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};