/*
题目：26 % 买卖股票的最佳时机 III 中等

题目大意：
给定一个数组，表示每天的股票价格。问最多交易两次的情况下，最大的收益是多少？

解题思路：
从左往右扫一遍，然后从右往左再扫一遍。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.size() < 2) return 0;
        vector<int> left(prices.size(), 0);
        int small = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            left[i] = max(left[i-1], prices[i]-small);
            if (small > prices[i]) {
                small = prices[i];
            }
        }
        int ret = left[prices.size()-1];
        int big = prices[prices.size()-1];
        int right = 0;
        for (int i = prices.size()-2; i > 0; --i) {
            if (big - prices[i] > right) {
                right = big - prices[i];
            }
            if (prices[i] > big) {
                big = prices[i];
            }
            if (left[i-1] + right > ret) {
                ret = left[i-1] + right;
            }
        }
        return ret;
    }
};
