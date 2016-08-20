/*
题目大意：
股票交易，次数限制为k

解题思路：
动态规划

遇到的问题：
这个题可折腾死我了。
前面那个解到现在不知道为啥就是runtime error
之后看了别人的想法，竟然还有k太大而runtime error的。无语了

总体来说就是，对于这种题目，空间能压缩就压缩了。
另外就是一定要注意空间申请的大小是不是够用。

再次阅读：
动归没啥问题，挺好的。
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices){
        if(prices.size() < 2)return 0;
        if(k > prices.size())return maxProfit2(prices);
        vector<int> sold(k+1, 0), buy(k+1, INT_MIN);
        for(int i = 0; i < prices.size(); ++i){
            for(int j = 1; j <= k; ++j){
                int new_buy = max(buy[j], sold[j-1]-prices[i]);
                int new_sold = max(sold[j], buy[j]+prices[i]);
                buy[j] = new_buy;
                sold[j] = new_sold;
            }
        }
        return sold[k];
    }

    int maxProfit_test(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2, 0)));

        if(prices.size() < 2)return 0;
        if(k > prices.size()/2)return maxProfit2(prices);
        for(int i = 0; i < k; ++i){
            dp[0][i][1] = -prices[0];
        }
        for(int i = 1; i < prices.size(); ++i){
            for(int j = 0; j < k; ++j){
                dp[i][j][1] = max(dp[i-1][j][0]-prices[i], dp[i-1][j][1]);
            }
            for(int j = 1; j <= k; ++j){
                dp[i][j][k] = max(dp[i-1][j-1][1]+prices[i], dp[i-1][j][0]);
            }
        }
        return dp[prices.size()-1][k][0];
    }

    int maxProfit2(vector<int>& prices) {
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
这次做的还不是很好。
首先就是忘记了当k很大的时候的情形，所以出现了RTE
另外就是空间没有压缩，如果能考虑清楚的话，面试的时候可以压缩一下。
*/
class Solution {
private:
    int maxProfitWithoutLimit(vector<int> &prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) ret += diff;
        }
        return ret;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k < 1) return 0;

        int n = prices.size();
        if (k*2 >= n) return maxProfitWithoutLimit(prices);

        vector<vector<int> > buy(n+1, vector<int>(k+1, 0)), sell(buy);


        for (int i = 0; i <= k; ++i) {
            buy[0][i] = INT_MIN;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = max(buy[i-1][j], sell[i-1][j-1]-prices[i-1]);
                sell[i][j] = max(sell[i-1][j], buy[i-1][j]+prices[i-1]);
            }
        }

        return sell[n][k];
    }
};
/*
 * found new land.
 */
class Solution {
private:
    int maxProfitWithoutLimit(const vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
        }
        return ans;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        if (k*2 >= prices.size()) return maxProfitWithoutLimit(prices);
        if (k <= 0) return 0;

        vector<vector<int>> dp(k+1, vector<int>(prices.size()));
        for (int i = 1; i <= k; ++i) {
            int localMax = -prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                dp[i][j] = max(dp[i][j-1], prices[j] + localMax);
                localMax = max(localMax, dp[i-1][j-1] - prices[j]);
            }
        }
        return dp[k][prices.size()-1];
    }
};
