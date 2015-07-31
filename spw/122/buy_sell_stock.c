#include <stdio.h>
#include <stdlib.h>

#define N 100
/**
 * Problem: Say you have an array for which the ith element is the price of a given stock on day i.
 *          Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 * Solve: find every increment interval of the market curve.
 * Tips: notice than you can try as many times as you can
 */
int maxProfit(int* prices, int pricesSize) {
	int total_profits = 0;
	int i;
	for (i = 1; i < pricesSize; ++i) {
		if (prices[i] > prices[i-1])
			total_profits += (prices[i] - prices[i-1]);
	}

	return total_profits;
}

int main()
{
	int prices[N];
	int n;
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &prices[i]);
		}
		int max_profit = maxProfit(prices, n);
		printf("The max profit is %d.\n", max_profit);
	}

	return 0;
}
