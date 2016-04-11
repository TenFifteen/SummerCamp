/*
题目大意：
经典买股票II

解题思路：
见代码。

遇到的问题：
没有。
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
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) ans += prices[i]-prices[i-1];
        }
        return ans;
    }
};