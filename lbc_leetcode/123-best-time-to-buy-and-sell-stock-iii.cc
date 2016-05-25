/*
题目大意：
给定一个n天的股票价格，求出最多交易两次的最大收益。

解题思路：
从前往后算一遍一次交易，从后往前算一遍一次交易。然后遍历中间点，找出两次交易的最大。

遇到的问题；
一开始是想着划分成两段的，但是复杂度是n*n的。所以超时了。
又想着用动态规划，不过感觉有点难写，看了别人的解。感觉很是巧妙。
而且写的过程中下标经常弄错。

再次阅读：
虽然这次一下子想到了这种解法，但是还是考虑着是否可以优化掉n的空间使用。
然后就在DISCUSS中找到了这种解法：
public class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
}
感觉巧妙极了。相当于把两次买卖看做四个步骤，每看一个股价，都更新一下这四个状态。
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
/*
第二次做：
这次还是搞错了一个东西，排查了好久。
不过这次有一个教训就是：“required from here”通常是min和max函数的参数太多了。
解题思路没有问题，不过还是要看一看DISCUSS中的去掉n空间的解法。其实就是将其划分为了四个阶段，
本质就是一个动态规划。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        vector<int> ans(prices.size(), 0);
        int buy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            ans[i] = max(ans[i-1], prices[i]-buy);
            buy = min(buy, prices[i]);
        }
        
        int ret = ans.back(), sell = -1;
        for (int i = prices.size()-1; i > 0; --i) {
            int deal = max(0, sell-prices[i]);
            sell = max(sell, prices[i]);
            ret = max(ret, ans[i-1] + deal);
        }
        ret = max(ret, sell-prices.front());
        
        return ret;
    }
};