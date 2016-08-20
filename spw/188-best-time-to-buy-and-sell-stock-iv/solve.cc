/**
 * Problem: Say you have an array for which the ith element is the price of a given stock on day i.
 *          Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * Solve: see comments below.
 * Tips: no
 */
class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            // if k is big enough then return the max
            // every transaction contain a buy and a sell
            if (k > n/2) {
                int ans = 0;
                for (int i = 1; i < n; ++i) {
                    ans += max(prices[i]-prices[i-1], 0);
                }
                return ans;
            }

            vector<vector<int>> dp(k+1, vector<int>(n, 0));

            // use the before best profit and the now prices as the base
            // keep a max base in every inner loop of the prices.
            for (int i = 1; i <= k; ++i) {
                int base = -prices[0];
                for (int j = 1; j < n; ++j) {
                    dp[i][j] = max(dp[i][j-1], base + prices[j]);
                    base = max(base, dp[i-1][j]-prices[j]);
                }
            }

            return dp[k][n-1];
        }
};
