/*
题目：51 % 买卖股票的最佳时机 II 中等

题目大意：
给定一个数组，表示每天的股票的价格。问不限制交易的次数，最大的收益是多少

解题思路：
相当于找到所有的上升区间

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
        int ret = 0;
        int index = 1;
        int small = 0;
        while (index < prices.size()) {
            while (index < prices.size() && prices[index] <= prices[index-1]) index++;
            small = index-1;
            while (index < prices.size() && prices[index] >= prices[index-1]) index++;
            ret += prices[index-1] - prices[small];
        }
        return ret;
    }
};
