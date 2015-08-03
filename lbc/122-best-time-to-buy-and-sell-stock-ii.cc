/*
题目大意：
给定一个数组，表示n天的股票价格。问如果不限制股票交易的次数，最大收益是多少？

解题思路：
由于股票的价格曲线应该是一个波浪形曲线，只需要找到每一段上升区间，并将其交易即可。

遇到的问题：
没有问题。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)return 0;
        int lowest = 0;
        int ret = 0;
        while(lowest < prices.size()-1){
            while(lowest < prices.size()-1 && prices[lowest] > prices[lowest+1])lowest++;
            int high = lowest+1;
            while(high < prices.size()-1 && prices[high] < prices[high+1])high++;
            if(lowest >= prices.size()-1)break;
            ret += prices[high]-prices[lowest];
            lowest = high+1;
        }
        return ret;
    }
};