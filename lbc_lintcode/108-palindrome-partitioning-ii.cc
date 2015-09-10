/*
题目：20 % 分割回文串 II 中等

题目大意：
给定一个字符串，问将字符串划分为所有字串都是回文串的最小的划分方法是多少

解题思路：
动归。
但是一开始想的动归麻烦了一点。
参考了一下之前leetcode上的解法，将复杂度下降了一个n
之所以可以这样，是因为，一个字符串的最小分割前面肯定有一个回文子串，所以只要考虑该串的长度就行了。

遇到的问题：
虽然是动归会做了，但是还是没有将这个题目化到最简
*/
class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        if (s.size() < 2) return 0;
        vector<vector<bool>> buf(s.size(), vector<bool>(s.size(), true));
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j <= s.size()-i; ++j) {
                if (s[j] == s[j+i-1] && (i == 2 || buf[j+1][j+i-2])) {
                    buf[j][j+i-1] = true;
                } else {
                    buf[j][j+i-1] = false;
                }
            }
        }
        vector<int> dp(s.size(), INT_MAX);
        dp[s.size()-1] = 0;
        for (int i = s.size()-2; i >= 0; --i) {
            if (buf[i][s.size()-1]) {
                dp[i] = 0;
            } else {
                for (int j = i; j < s.size()-1; ++j) {
                    if (buf[i][j]) {
                        dp[i] = min(dp[i], dp[j+1]+1);
                    }
                }
            }
        }
        return dp[0];
    }

    int minCut2(string s) {
        // write your code here
        if (s.size() < 2) return 0;
        vector<vector<bool>> buf(s.size(), vector<bool>(s.size(), true));
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j <= s.size()-i; ++j) {
                if (s[j] == s[j+i-1] && (i == 2 || buf[j+1][j+i-2])) {
                    buf[j][j+i-1] = true;
                } else {
                    buf[j][j+i-1] = false;
                }
            }
        }
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), INT_MAX));
        for (int len = 1; len <= s.size(); ++len) {
            for (int start = 0; start+len <= s.size(); ++start) {
                if (buf[start][start+len-1]) {
                    dp[start][start+len-1] = 0;
                } else {
                    for (int i = 1; i < len; ++i) {
                        if (dp[start][start+i-1] + dp[start+i][start+len-1] + 1 < dp[start][start+len-1]) {
                            dp[start][start+len-1] = dp[start][start+i-1] + dp[start+i][start+len-1] + 1;
                        }
                    }
                }
            }
        }
        return dp[0][s.size()-1];
    }
};


