/*
题目：26 % 交叉字符串 中等

题目大意：
给定两个字符串，问两个字符串通过交织的方式，是否可以组成第三条字符串。

解题思路：
标准的动态规划

遇到的问题：
一开始将下标搞错了，查了好久。
另外，这个题目的空间复杂度可以降低到一维。
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
        if (s1.size() + s2.size() != s3.size()) return false;
        if (s1 == "") return s2 == s3;
        if (s2 == "") return s1 == s3;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, true));
        for (int i = 0; i < s1.size(); ++i) {
            dp[i+1][0] = dp[i][0] && s1[i] == s3[i];
        }
        for (int i = 0; i < s2.size(); ++i) {
            dp[0][i+1] = dp[0][i] && s2[i] == s3[i];
        }
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
