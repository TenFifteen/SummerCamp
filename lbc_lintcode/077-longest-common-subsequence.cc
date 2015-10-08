/*
题目：37 % 最长公共子序列 中等

题目大意：
求两个字符串的最长公共子序列

解题思路：
动归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if (A.size() == 0 || B.size() == 0) return 0;
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                if (A[i] == B[j]) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
};

