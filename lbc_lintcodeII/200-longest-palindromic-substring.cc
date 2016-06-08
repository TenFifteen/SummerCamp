/*
题目大意：
给定一个字符串，找出其中最长的回文子串。

解题思路：
Manchester算法。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        string str(s.size()*2+1, '#');
        for (int i = 0; i < s.size(); ++i) {
            str[i*2+1] = s[i];
        }
        
        vector<int> dp(str.size(), 1);
        int id = 0, mx = 0, ans = 0;
        for (int i = 1; i < str.size(); ++i) {
            if (mx > i) {
                dp[i] = dp[id*2-i];
                if (dp[i]+i-1 > mx) {
                    dp[i] = mx-i+1;
                }
            }
            
            while (i-dp[i] >= 0 && i+dp[i] < str.size() && 
                str[i-dp[i]] == str[i+dp[i]]) dp[i]++;
            if (dp[i]+i-1 > mx) {
                mx = dp[i]+i-1;
                id = i;
            }
            if (dp[i] > dp[ans]) ans = i;
        }
        
        if (ans & 0x1) {
            return s.substr((ans-dp[ans]+1)/2, dp[ans]-1);
        } else {
            return s.substr((ans-dp[ans]+2)/2, dp[ans]-1);
        }
    }
};
