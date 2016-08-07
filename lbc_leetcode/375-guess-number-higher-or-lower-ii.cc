/*
 * good question. and good answer.
 */
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int k = 1; k < n; ++k) {
            for (int i = 1; i+k <= n; ++i) {
                dp[i][i+k] = min(dp[i+1][i+k]+i, dp[i][i+k-1]+i+k);
                for (int j = i+1; j < i+k; ++j) {
                    dp[i][i+k] = min(dp[i][i+k], max(dp[i][j-1], dp[j+1][i+k]) + j);
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[1][n];
    }
};
