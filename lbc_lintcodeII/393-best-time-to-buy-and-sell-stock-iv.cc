/*
题目大意：
给定一个数组，表示股票的价格。最多交易k次，问最大收益。

解题思路：
动规。

遇到的问题：
思路是没有问题的，只是实施起来老是出现问题。
最后看了一下之前的代码，才发现两层循环竟然是反着的。
但是还是没有清楚的想明白为啥之前的对，现在的不对了。。。
*/
class Solution {
    int maxProfitWithoutLimit(const vector<int> &prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
    
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        if (k <= 0) return 0;
        
        if (k*2 >= prices.size()) {
            return maxProfitWithoutLimit(prices);
        }
        
        int n = prices.size();
        vector<vector<int>> sell(n+1, vector<int>(k+1)), buy(n+1, vector<int>(k+1, INT_MIN));
        /*for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                sell[i][j] = max(sell[i-1][j], buy[i-1][j-1]+prices[i-1]);
                buy[i][j] = max(buy[i-1][j], sell[i-1][j]-prices[i-1]);
            }
        }*/
        for (int j = 1; j <= k; ++j) {  //why this is right, and above is wrong...
            buy[1][j] = -prices[0];
            for (int i = 2; i <= n; ++i) {
                sell[i][j] = max(sell[i-1][j], buy[i-1][j] + prices[i-1]);
                buy[i][j] = max(buy[i-1][j], sell[i-1][j-1] - prices[i-1]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i <= k; ++i) {
            ans = max(ans, sell[n][i]);
        }
        
        return ans;
    }
};
