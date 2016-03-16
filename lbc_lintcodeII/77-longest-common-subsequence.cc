/*
题目大意：
给定两个字符串，问他们的最大的公共子序列的长度是多少？

解题思路：
dp

遇到的问题：
没有。
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
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= B.size(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (A[i-1] == B[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
        
        return dp[A.size()][B.size()];
    }
};
