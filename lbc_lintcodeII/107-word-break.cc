/*
题目大意：
给定一组单词，一个字符串。问该字符串是否可以拆分成单词。

解题思路：
动归

遇到的问题：
一开始没有加max，min优化，结果还超时了。
*/
class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        if (s.size() == 0) return true;
        if (dict.size() == 0) return false;
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        int maxlen = 0, minlen = INT_MAX;
        for (auto s : dict) {
            maxlen = max(maxlen, (int)s.size());
            minlen = min(minlen, (int)s.size());
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i-minlen+1; j > max(i-maxlen, 0); --j) {
                if (dict.find(s.substr(j-1, i-j+1)) != dict.end() && dp[j-1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};