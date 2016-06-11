/**
 * Problem: You are given coins of different denominations and a total
 *          amount of money amount. Write a function to compute the fewest
 *          number of coins that you need to make up that amount. If that
 *          amount of money cannot be made up by any combination of the
 *          coins, return -1.
 * Solve: complete backpack
 * Tips: see comments below.
 *
 */
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();

            vector<int> dp(amount+1, INT_MAX);

            dp[0] = 0;// initial : 0 or 1, determined by the left.
            for (int i = 0; i < n; ++i) {
                for (int j = coins[i]; j <= amount; ++j) {
                    // must make sure that the dp[j-coints[i]] is valid
                    if (dp[j-coins[i]] != INT_MAX)
                        dp[j] = min(dp[j], dp[j-coins[i]]+1);
                }
            }

            return dp[amount] == INT_MAX ? -1 : dp[amount];
        }
};
