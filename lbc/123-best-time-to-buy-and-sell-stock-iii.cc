/*
题目大意：
给定一个n天的股票价格，求出最多交易两次的最大收益。

解题思路：
从前往后算一遍一次交易，从后往前算一遍一次交易。然后遍历中间点，找出两次交易的最大。

遇到的问题；
一开始是想着划分成两段的，但是复杂度是n*n的。所以超时了。
又想着用动态规划，不过感觉有点难写，看了别人的解。感觉很是巧妙。
而且写的过程中下标经常弄错。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)return 0;
        vector<int> ans1(prices.size(), 0), ans2(prices.size(), 0);
        int low = prices[0], high = prices[prices.size()-1];
        for(int i = 1; i < prices.size(); ++i){
            ans1[i] = max(prices[i]-low, ans1[i-1]);
            low = min(low, prices[i]);
            ans2[i] = max(ans2[i-1], high-prices[prices.size()-i-1]);
            high = max(prices[prices.size()-i-1], high);
        }
        int ret = 0;
        for(int i = 1; i < prices.size()-1; ++i){
            if(ans1[i] + ans2[prices.size()-1-i] > ret){
                ret = ans1[i] + ans2[prices.size()-1-i];
            }
        }
        if(ans1[prices.size()-1] > ret){
            ret = ans1[prices.size()-1];
        }
        return ret;
    }
};