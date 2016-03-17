/*
题目大意：
给定三个字符串，问s3是否可以由s1和s2两个交织而成？

解题思路：
dp

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if (s1.size()+s2.size() != s3.size()) return false;
        
        int n1 = s1.size(), n2 = s2.size();
        vector<bool> dp(n1+1, false);
        dp[0] = true;
        for (int i = 1; i <= n1; ++i) {
            if (s1[i-1] != s3[i-1]) break;
            dp[i] = true;
        }
        
        for (int i = 1; i <= n2; ++i) {
            if (s2[i-1] != s3[i-1]) dp[0] = false;
            
            for (int j = 1; j <= n1; ++j) {
                bool newValue = false;
                if (s2[i-1] == s3[i+j-1]) newValue |= dp[j];
                if (s1[j-1] == s3[i+j-1]) newValue |= dp[j-1];
                dp[j] = newValue;
            }
        }
        
        return dp[n1];
    }
};