/*
题目大意：
给定两个字符串。问T在S的子序列中的个数。

解题思路：
动归。

遇到的问题：
没有。
*/
class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        vector<int> dp(T.size()+1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < S.size(); ++i) {
            for (int j = T.size(); j > 0; --j) {
                if (S[i] == T[j-1]) dp[j] += dp[j-1];
            }
        }
        
        return dp[T.size()];
    }
};
