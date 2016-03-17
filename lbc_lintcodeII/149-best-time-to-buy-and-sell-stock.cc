/*
题目大意：
给定一个数组，表示每天股票的价格。只能交易一次，问最大的收益是多少？

解题思路：
遍历一遍，记录之前的最小值。

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
        
        int ans = 0, m = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            ans = max(ans, prices[i]-m);
            m = min(m, prices[i]);
        }
        return ans;
    }
};
