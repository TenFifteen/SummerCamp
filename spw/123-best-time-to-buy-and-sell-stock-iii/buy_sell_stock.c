#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
/**
 * Problem: say you have an array for which the ith element is the price
 *          of a given stock on day i, Design an algorithm to find the maximum profit.
 *          You should complete it at most two transactions.
 * Solve: find the most elegant code in the discuss board.
 * Tips: if we only have to make one transaction, we use two variables: lowest_buy_price1
 *       and max_profit1. But we have two chances, and one must come after selling another,
 *       then we use four variables, then we get a solution the same way .
 */
int maxProfit(int* prices, int pricesSize) {
	if (pricesSize <= 1) return 0;

	int lowest_buy_price1 = prices[0];
	int lowest_buy_price2 = prices[0];

	int max_profit1 = 0;
	int max_profit2 = 0;

	int i = 1;
	while (i < pricesSize) {
		// notice the order of the code
		// it is the same way with that we only have one choices
		// we transfer the low_buy_price2 as it doesn't know anything about the the first transaction
		max_profit2 = max(max_profit2, prices[i] - lowest_buy_price2);
		lowest_buy_price2 = min(lowest_buy_price2, prices[i] - max_profit1);
		max_profit1 = max(max_profit1, prices[i] - lowest_buy_price1);
		lowest_buy_price1 = min(lowest_buy_price1, prices[i]);

        ++i;
	}

	return max_profit2;
}
int main()
{

}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int n = prices.size();
        int buy1 = prices[0], buy2 = prices[0], profit1 = 0, profit2 = 0;
        for (int i = 1; i < n; ++i) {
            profit2 = max(profit2, prices[i]-buy2);
            buy2 = min(buy2, prices[i]-profit1);
            profit1 = max(profit1, prices[i]-buy1);
            buy1 = min(buy1, prices[i]);
        }

        return profit2;
    }
};
