/*
题目大意：
给定一堆面值，问最少使用多少个硬币可以凑成amount数量

解题思路：
动归

遇到的问题：
没有太大问题，但是不知道这种直接使用INT_MAX来进行判断的形式是否合理？
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