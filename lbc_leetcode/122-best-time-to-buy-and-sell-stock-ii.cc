/*
题目大意：
给定一个数组，表示n天的股票价格。问如果不限制股票交易的次数，最大收益是多少？

解题思路：
由于股票的价格曲线应该是一个波浪形曲线，只需要找到每一段上升区间，并将其交易即可。

遇到的问题：
没有问题。

再次阅读：
虽然感觉没啥问题了，但是竟然在DISCUSS中看到这么一种牛逼的解法：
public class Solution {
public int maxProfit(int[] prices) {
    int total = 0;
    for (int i=0; i< prices.length-1; i++) {
        if (prices[i+1]>prices[i]) total += prices[i+1]-prices[i];
    }

    return total;
}
虽然道理是一样的，但是代码复杂度差太多了。
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
/*
第二次做：
买股票系列的第二简单的题目。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) ans += diff;
        }

        return ans;
    }
};
/*
 * some easy too
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
        }
        return ans;
    }
};
