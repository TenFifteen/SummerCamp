/**
 * Problem: Given two strings, find the longest common substring.
 *          Return the length of it.
 * Solve: dp
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A, B: Two string.
         * @return: the length of the longest common substring.
         */
        int longestCommonSubstring(string &A, string &B) {
            int m = A.size(), n = B.size();

            vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

            int ans = 0;
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (A[i-1] == B[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                        ans = max(ans, dp[i][j]);
                    }
                }
            }

            return ans;
        }
};

