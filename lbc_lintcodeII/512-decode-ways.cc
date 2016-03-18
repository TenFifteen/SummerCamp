/*
题目大意：
给定一串digit，问能够解析成26进制的多少种方案？

解题思路：
动归。

遇到的问题：
没有问题。
*/
class Solution {
    
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if (s.size() == 0) return 0;
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == '0') dp[i] = 0;
            else {
                dp[i] = dp[i+1];
                if (i != n-1 && stoi(s.substr(i, 2)) <= 26) dp[i] += dp[i+2];
            }
        }
        
        return dp[0];
    }
};