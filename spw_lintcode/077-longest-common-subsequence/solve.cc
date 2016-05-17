/**
 * Problem: Given two strings, find the longest common subsequence (LCS).
 *          Your code should return the length of LCS.
 * Solve: dp
 * Tips: the state transformation
 */
class Solution {
    public:
        /**
         * @param A, B: Two strings.
         * @return: The length of longest common subsequence of A and B.
         */
        int longestCommonSubsequence(string A, string B) {
            int m = A.size(), n = B.size();

            vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (A[i-1] == B[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }

            return dp[m][n];
        }
};

