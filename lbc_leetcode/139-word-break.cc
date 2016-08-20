/*
题目大意：
给定一个字符串，一个字典。问是否可以将字符串划分为以字典中单词为单位的字串。

解题思路：
动态规划。

遇到的问题：
一次通过。

再次阅读：
这次想到的思路还是这个思路，看了一下DISCUSS，基本也就是这个思路了。
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
/*
第二次做：
还是一个动归。
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.size() == 0) return false;

        int minlen = INT_MAX, maxlen = INT_MIN;
        for (auto s : wordDict) {
            int n = s.size();
            minlen = min(minlen, n);
            maxlen = max(maxlen, n);
        }

        if (s.size() < minlen) return false;
        int n = s.size();

        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = minlen-1; i < n; ++i) {
            for (int j = i-minlen+1; j >= max(0, i-maxlen+1); --j) {
                if (dp[j] && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()) {
                    dp[i+1] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
/*
 * easy
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.size() == 0) return false;

        int max_len = INT_MIN, min_len = INT_MAX;
        for (auto w : wordDict) {
            int len = w.size();
            max_len = max(max_len, len);
            min_len = min(min_len, len);
        }

        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = min_len; i <= s.size(); ++i) {
            for (int j = i-min_len; j >= max(0, i-max_len); --j) {
                if (dp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
