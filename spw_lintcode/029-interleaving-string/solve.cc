/**
 * Problem: Given three strings: s1, s2, s3, determine whether s3 is
 *          formed by the interleaving of s1 and s2.
 * Solve: dp, a path is can walk right or down.
 * Tips: no
 */
class Solution {
    public:
        /**
         * Determine whether s3 is formed by interleaving of s1 and s2.
         * @param s1, s2, s3: As description.
         * @return: true of false.
         */
        bool isInterleave(string s1, string s2, string s3) {
            int m = s1.size(), n = s2.size(), total = s3.size();
            if (total != m+n) return false;

            vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
            dp[0][0] = true;
            for (int i = 1; i <= m && dp[i-1][0]; ++i) dp[i][0] = s3[i-1] == s1[i-1];
            for (int j = 1; j <= n && dp[0][j-1]; ++j) dp[0][j] = s3[j-1] == s2[j-1];

            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dp[i][j] = dp[i-1][j] && s3[i+j-1] == s1[i-1]
                        || dp[i][j-1] && s3[i+j-1] == s2[j-1];
                }
            }

            return dp[m][n];
        }
};
