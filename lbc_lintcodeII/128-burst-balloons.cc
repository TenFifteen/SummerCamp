/*
题目大意：
给定一组气球，气球爆炸得到的分数是该气球乘以两边的气球的数字。问最大的得分是多少？

解题思路：
动归。

遇到的问题：
各种下标问题。
*/
class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */  
    int maxCoins(vector<int>& nums) {
        // Write your code here
        if (nums.size() == 0) return 0;
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i+len <= n; ++i) {
                for (int j = i; j < i+len; ++j) {
                    int left = i == 0 ? 1 : nums[i-1];
                    int right = i+len == n ? 1 : nums[i+len];
                    
                    int cur = 0;
                    if (j != i) cur += dp[i][j-1];
                    if (j != i+len-1) cur += dp[j+1][i+len-1];
                    cur += left * nums[j] * right;
                    dp[i][i+len-1] = max(dp[i][i+len-1], cur);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
