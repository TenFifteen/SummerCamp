/**
 * Problem: Say you have an array for which the ith element is the price 
 *          of a given stock on day i. If you were only permitted to complete 
 *          at most one transaction (ie, buy one and sell one share of the stock), 
 *          design an algorithm to find the maximum profit.
 * Solve: use one variable to save the minimum stock of prices[0...i], then we can get
 *        the maximum profit of selling stock in day i.
 */
int maxProfit(int* prices, int pricesSize) {
	if (pricesSize <= 1) return 0;  

	int min_stock = prices[0];
	int max_profit = 0;
	int i;
	for (i = 1; i < pricesSize; ++i) {
		int now_profit = prices[i] - min_stock;
		max_profit = now_profit > max_profit ? now_profit : max_profit;
		min_stock = min_stock < prices[i] ? min_stock : prices[i];
	}

	return max_profit;
}
