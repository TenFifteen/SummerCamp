/**
 * Problem: Say you have an array for which the ith element is the price of a given stock on day i.
 *          Design an algorithm to find the maximum profit. You may complete as many transactions
 *          as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 *
 *          You may not engage in multiple transactions at the same time
 *          (ie, you must sell the stock before you buy again).
 *          After you sell your stock, you cannot buy stock on next day.
 *          (ie, cooldown 1 day)
 * Solve: dp, two state and depend each other
 * Tips: initialize
 */
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            if (n < 2) return 0;

            vector<int> buy(n), sell(n);
            sell[0] = 0, buy[0] = -prices[0];
            sell[1] = max(0, prices[1]-prices[0]);
            buy[1] = max(-prices[0], -prices[1]);

            for (int i = 2; i < n; ++i) {
                buy[i] = max(sell[i-2]-prices[i], buy[i-1]);
                sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
            }

            return sell[n-1];
        }
};
