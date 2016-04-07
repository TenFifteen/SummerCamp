/**
 * Problem: Implement wildcard pattern matching with support for '?' and '*'.
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * Solve: dp
 * Tips: initialization when j = 0;
 */
class Solution {
    public:
        /**
         * @param s: A string
         * @param p: A string includes "?" and "*"
         * @return: A boolean
         */
        bool isMatch(const char *s, const char *p) {
            int n = strlen(s), m = strlen(p);
            vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));

            dp[0][0] = true;
            for (int i = 1; i <= m; ++i)
                if (p[i-1] == '*') dp[i][0] = dp[i-1][0];

            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (p[i-1] == '*') {
                        dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                    } else {
                        if (p[i-1] == '?' || p[i-1] == s[j-1])
                            dp[i][j] = dp[i-1][j-1];
                    }
                }
            }

            return dp[m][n];
        }
};
