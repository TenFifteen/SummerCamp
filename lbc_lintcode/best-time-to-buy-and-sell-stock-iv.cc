/*
题目：22 % 买卖股票的最佳时机 IV 困难

题目大意：
给定一个数组，每个值表示股票当天的价格。给定k次交易机会，问最大的收益是多少？

解题思路：
首先，如果k的值大于n的一半的话，则可以认为交易次数是不限制的。
然后剩下的情况，用动归解。

遇到的问题：
一开始没有考虑k太大的情况，然后就是动归的时候空间太大。
*/
class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        if (prices.size() == 0 || k <= 0) return 0;
        
        if (k > prices.size()) {
            int ret = 0;
            int index = 0;
            while (index+1 < prices.size() && prices[index] >= prices[index+1]) {
                index++;
            }
            if (index+1 == prices.size()) return 0;
            
            while (index+1 < prices.size()) {
                int front = index+1;
                while (front+1 < prices.size() && prices[front] <= prices[front+1]) {
                    front++;
                }
                ret += prices[front] - prices[index];
                index = front+1;
                while (index+1 < prices.size() && prices[index] >= prices[index+1]) {
                    index++;
                }
            }
            
            return ret;
        }
        
        int n = prices.size();
        vector<vector<int> > sell(n, vector<int>(k+1));
        vector<vector<int> >  buy(n, vector<int>(k+1));
        for (int i = 1; i <= k; ++i) {
            buy[0][i] = -prices[0];
            for (int j = 1; j < n; ++j) {
                sell[j][i] = max(sell[j-1][i], buy[j-1][i]+prices[j]);
                buy[j][i]  = max(buy[j-1][i], sell[j-1][i-1]-prices[j]);
            }
        }
        return sell[n-1][k];
    }
};
