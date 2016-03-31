/*
题目大意：
求两个字符串的编辑距离。

解题思路：
动归。

遇到的问题：
没有。
*/
class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i < word2.size(); ++i) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};
