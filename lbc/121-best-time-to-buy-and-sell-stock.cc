/*
题目大意：
给定一个数组，表示n天的股票价格。问，只有一次交易的话，最大的收益是多少？

解题思路：
找到前k天最小值，然后如果第k+1天卖出大于ret的话就更新；如果k+1天比最小值还小，
就更新最小值。

遇到的问题：
没有问题。

再次阅读：
非常简单。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)return 0;
        int lowest = prices[0];
        int ret = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] - lowest > ret){
                ret = prices[i] - lowest;
            }
            if(prices[i] < lowest){
                lowest = prices[i];
            }
        }
        if(ret < 0)return 0;
        else return ret;
    }
};