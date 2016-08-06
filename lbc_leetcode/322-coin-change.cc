/*
题目大意：
给定一堆面值，问最少使用多少个硬币可以凑成amount数量

解题思路：
动归

遇到的问题：
没有太大问题，但是不知道这种直接使用INT_MAX来进行判断的形式是否合理？

再次阅读：
感觉之前写的这个动归已经是很不错了。看了下DISCUSS，基本也就是这样子了。
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX/2);
        dp[0] = 0;

        sort(coins.begin(), coins.end());

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i-coins[j]]+1, dp[i]);
                }
            }
        }

        return dp[amount] == INT_MAX/2 ? -1 : dp[amount];
    }
};
/*
第二次做：
动归。
问题不是很大。
*/
/*
 * it seems that I forget to post my second answer.
 * this time is ok
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;

        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i]) dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }

        if (dp[amount] > amount) return -1;
        else return dp[amount];
    }
};


