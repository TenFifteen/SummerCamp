/*
题目大意：
给定一个数组，表示股票每天的价格。现在有无数次的交易机会，但是如果昨天卖了，今天不可以买，称为
cooldown。问在这种情况下，总收益最大是多少？

解题思路：
就是一个动归的思路，就是当前的股票买、还是卖、还是cooldown，都是从昨天的三种状态中获得的。

遇到的问题：
一开始都没感觉自己的代码是对的，竟然就通过了。

再次阅读：
DISCUSS中基本也就是这种思路，最多就是中间再省几个变量。其实三个变量相当于是一个依赖环。至少还需要一个
额外变量。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int buy = -prices[0], sell = 0, cooldown = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int new_buy = max(cooldown - prices[i], buy);
            int new_sell = max(buy + prices[i], sell);
            int new_cooldown = max(cooldown, sell);

            buy = new_buy;
            sell = new_sell;
            cooldown = new_cooldown;
        }

        return max(sell, cooldown);
    }
};
/*
第二次做：
动态规划，没有太大问题。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return false;

        int sell1 = 0, sell2 = 0, buy = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            int newbuy = max(buy, sell1-prices[i]);
            int newsell = max(sell2, buy+prices[i]);
            sell1 = sell2;
            sell2 = newsell;
            buy = newbuy;
        }

        return sell2;
    }
};
/*
 * ok
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int sell_last = 0, buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int new_buy = max(buy, sell_last-prices[i]);
            int new_sell = max(sell, buy+prices[i]);
            sell_last = sell;
            sell = new_sell;
            buy = new_buy;
        }

        return sell;
    }
};


