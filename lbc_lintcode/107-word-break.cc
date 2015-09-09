/*
题目：12 % 单词切分 中等

题目大意：
给定一个字符串，一个字典。问是否可以将字符串拆分成所有单词都在字典中查到

解题思路：
动归

遇到的问题：
没有问题。
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
        int len = 0;
        for (auto d : dict) {
            if (d.size() > len) {
                len = d.size();
            }
        }
        vector<bool> dp(s.size(), false);
        for (int i = 1; i <= min(len, (int)s.size()); ++i) {
            if (dict.find(s.substr(0, i)) != dict.end()) {
                dp[i-1] = true;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (dp[i]) continue;
            for (int j = i; j >= max(0, i-len+1); --j) {
                if ((j == 0 ||dp[j-1]) && dict.find(s.substr(j, i-j+1)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()-1];
    }
};
