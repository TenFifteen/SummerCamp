/*
题目大意：
经典买股票III

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
        
        int n = prices.size();
        vector<int> left(n, 0);
        int buy = prices[0];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i-1], prices[i]-buy);
            buy = min(buy, prices[i]);
        }
        
        int ans = left[n-1], pro = 0, sell = prices[n-1];
        for (int i = n-2; i >= 0; --i) {
            pro = max(pro, sell-prices[i]);
            sell = max(sell, prices[i]);
            
            if (i > 0) {
                ans = max(ans, pro+left[i-1]);
            }
        }
        
        return ans;
    }
};