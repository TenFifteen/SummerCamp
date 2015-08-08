/*
题目大意：
给定一个字符串，一个字典。问是否可以将字符串划分为以字典中单词为单位的字串。

解题思路：
动态规划。

遇到的问题：
一次通过。
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size() == 0)return true;
        vector<bool> dp(s.size(), false);
        dp[0] = wordDict.count(s.substr(0,1)) == 1;
        for(int i = 1; i < s.size(); ++i){
            if(wordDict.count(s.substr(0, i+1))){
                dp[i] = true;
            }
            for(int j = i; dp[i] == false && j > 0; --j){
                if(wordDict.count(s.substr(j, i-j+1)) && dp[j-1]){
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()-1];
    }
};