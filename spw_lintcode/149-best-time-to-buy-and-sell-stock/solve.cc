/**
 * Problem: Say you have an array for which the ith element is the price of a given stock on day i.
 *          If you were only permitted to complete at most one transaction (ie, buy one and sell
 *          one share of the stock), design an algorithm to find the maximum profit.
 * Solve: find every max profit in the i place we can get
 * Tips: no
 */
class Solution {
    public:
        /**
         ** @param prices: Given an integer array
         ** @return: Maximum profit
         **/
        int maxProfit(vector<int> &prices) {
            int buy = INT_MAX;

            int profit = 0;
            int n = prices.size();
            for (int i = 0; i < n; ++i) {
                profit = max(profit, prices[i]-buy);
                buy = min(buy, prices[i]);

            }

            return profit;

        }

};
