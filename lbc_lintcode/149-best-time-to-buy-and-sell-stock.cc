/*
题目：41 % 买卖股票的最佳时机 中等

题目大意：
给定一个数组，表示股票每天的价格，问最多交易一次的最大收益是多少

解题思路：
直接遍历

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
        int ret = 0;
        int small = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i]-small > ret) {
                ret = prices[i] - small;
            }
            if (prices[i] < small) {
                small = prices[i];
            }
        }
        return ret;
    }
};

