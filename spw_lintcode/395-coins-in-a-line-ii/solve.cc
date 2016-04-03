/**
 * Problem: There are n coins with different value in a line. Two players
 *          take turns to take one or two coins from left side until there
 *          are no more coins left. The player who take the coins with the most value wins.
 * Solve: dp[i] represents the max value first player can get from index i to n-1
 * Tips: if dp[i+3] does not exist, assign it to zero
 */
class Solution {
    public:
        /**
         * @param values: a vector of integers
         * @return: a boolean which equals to true if the first player will win
         */
        bool firstWillWin(vector<int> &values) {
            int n = values.size();
            if (n < 3) return true;

            vector<int> dp(n , 0);
            dp[n-1] = values[n-1];
            dp[n-2] = values[n-1] + values[n-2];

            for (int i = n-3; i >= 0; --i) {
                int dp2 = i + 2 < n ? dp[i+2] : 0;
                int dp3 = i + 3 < n ? dp[i+3] : 0;
                int dp4 = i + 4 < n ? dp[i+4] : 0;

                int value1 = values[i] + min(dp2, dp3);
                int value2 = values[i] + values[i+1] + min(dp3, dp4);

                dp[i] = max(value1, value2);
            }

            int sum = 0;
            for (int i = 0; i < n; ++i) sum += values[i];

            return sum - dp[0] < dp[0];
        }
};
