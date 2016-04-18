/**
 * Problem:Given a string S and a string T, count the number of
 *         distinct subsequences of T in S.
 *
 *         A subsequence of a string is a new string which is formed
 *         from the original string by deleting some (can be none) of
 *         the characters without disturbing the relative positions
 *         of the remaining characters.
 *         (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * Solve: dp
 * Tips: initialize, when t = "" and s.size() > 0, we should use
 *       dp[i][0] = 1 that is : when s = "d" t = "d", then this will
 *       be initialize correctly dp[1][1] = dp[0][1] (0)+ dp[0][0](1)
 */
class Solution {
    public:
        /**
         * @param S, T: Two string.
         * @return: Count the number of distinct subsequences
         */
        int numDistinct(string &S, string &T) {
            int m = S.size(), n = T.size();
            vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
            for (int i = 0; i <= m; ++i) dp[i][0] = 1;

            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    // if s add one character, it will certainly at least
                    // have the origin possible.
                    dp[i][j] = dp[i-1][j];

                    // 1. the above case: not include the end character.
                    // 2. include the end character in S
                    // then the two cases are mutual exclusion.
                    if (S[i-1] == T[j-1]) {
                        dp[i][j] += dp[i-1][j-1];
                    }
                }
            }

            return dp[m][n];
        }
};
