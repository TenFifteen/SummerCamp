/**
 * Problem: Say you have an array for which the ith element is the price of a given stock on day i.
 *          Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * Solve: copy from the leetcode discuss board. https://leetcode.com/discuss/62026/clean-java-dp-solution-with-comment
 * Tips: no
 */
/**
 ** dp[i, j] represents the max profit up until prices[j] using at most i transactions.
 ** dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1]  }
 **          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
 ** dp[0, j] = 0; 0 transactions makes 0 profit
 ** dp[i, 0] = 0; if there is only one price data point you can't make any transaction.
 **/
class Solution {
    public:
        /**
         * @param k: An integer
         * @param prices: Given an integer array
         * @return: Maximum profit
         */
        int maxProfit(int k, vector<int> &prices) {
            int n = prices.size();

            int maxProfit = 0;
            if (k >= n/2) {
                for (int i = 1; i < n; ++i) {
                    maxProfit += max(prices[i] - prices[i-1], 0);
                }
                return maxProfit;
            }

            vector<vector<int> > dp(k+1, vector<int>(n, 0));

            for (int i = 1; i <= k; ++i) {
                int maxBase = dp[i-1][0] - prices[0];
                for (int j = 1; j < n; ++j) {
                    dp[i][j] = max(dp[i][j-1], maxBase + prices[j]);
                    maxBase = max(maxBase, dp[i-1][j] - prices[j]);
                }
            }

            return dp[k][n-1];
        }
};
