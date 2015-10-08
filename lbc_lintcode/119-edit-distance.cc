/*
题目：29 % 编辑距离 中等

题目大意：
给定两个单词，求两个单词之间的编辑距离

解题思路：
动态规划

遇到的问题：
没有问题。
*/
class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i = 0; i < word1.size(); ++i) {
            dp[i+1][0] = i+1;
        }
        for (int i = 0; i < word2.size(); ++i) {
            dp[0][i+1] = i+1;
        }
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

