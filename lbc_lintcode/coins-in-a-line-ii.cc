/*
题目：28 % 硬币排成线 II 中等

题目大意：
给定一排硬币，每个硬币有一个value，然后从左往右拿，每个人每次拿一个或者两个。
问先手有没有必胜策略

解题思路：
动态规划

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        if (values.size() < 3) return true;
        vector<int> sum(values.size());
        sum[values.size()-1] = values[values.size()-1];
        for (int i = values.size()-2; i >= 0; --i) {
            sum[i] = sum[i+1] + values[i];
        }
        vector<int> dp(values.size());
        dp[values.size()-1] = sum[values.size()-1];
        dp[values.size()-2] = sum[values.size()-2];
        for (int i = values.size()-3; i >= 0; --i) {
            dp[i] = max(values[i]+sum[i+1]-dp[i+1], values[i]+values[i+1]+sum[i+2]-dp[i+2]);
        }
        return dp[0] > sum[0]-dp[0];
    }
};
