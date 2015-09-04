/*
题目：31 % 最长公共子串 中等

题目大意：
给定两个字符串，求最长公共字串

解题思路：
动态规划

遇到的问题：
没有问题。
*/
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        if (A.size() == 0 || B.size() == 0) return 0;
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    if (dp[i+1][j+1] > ans) {
                        ans = dp[i+1][j+1];
                    }
                }
            }
        }
        return ans;
    }
};

