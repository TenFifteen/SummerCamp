/*
题目大意：
给定一排硬币，硬币的value不同，一个人一次取一个或者两个，两个人轮流取，问先取的人是否有必胜把握。

解题思路：
动归。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        if (n == 0) return false;
        
        vector<int> sum(n);
        sum[n-1] = values[n-1];
        for (int i = n-2; i >= 0; --i) {
            sum[i] = sum[i+1]+values[i];
        }
        
        vector<int> dp(sum);
        for (int i = n-3; i >= 0; --i) {
            dp[i] = max(sum[i+1] - dp[i+1] + values[i], sum[i+2] - dp[i+2] + values[i] + values[i+1]);
        }
        
        return dp[0]*2 > sum[0];
    }
};