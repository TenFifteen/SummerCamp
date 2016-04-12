/**
 * Problem: Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Solve: use four variable
 * Tips: no
 */
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int buy1 = INT_MAX, profit1 = 0, buy2 = INT_MAX, profit2 = 0;

        int n = prices.size();

        for (int i = 0; i < n; ++i) {
            profit2 = max(profit2, prices[i]-buy2);
            buy2 = min(buy2, prices[i]-profit1);
            profit1 = max(profit1, prices[i]-buy1);
            buy1 = min(prices[i], buy1);
        }

        return profit2;
    }
};
