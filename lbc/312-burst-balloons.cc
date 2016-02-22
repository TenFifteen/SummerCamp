/*
题目大意：
给定一排气球，每个气球上面都有一个数字，爆裂这个气球的时候，会得到该气球和其相邻的两个气球三者乘积的金币。
两侧相当于有两个1的虚拟气球。问可以达到的最大的金币是多少？

解题思路：
动态规划。

遇到的问题：
动态规划写起来还是不是很熟，经常搞错了各种下标，其实条件啥的。
感觉这个算法实在是算法中的最难的一种了吧。

再次阅读：
动态规划，没有太大问题。但是还是得多练练。
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<vector<int> > dp(n, vector<int>(n, 0));
        
        dp[0][0] = nums[0] * nums[1];
        dp[n-1][n-1] = nums[n-1] * nums[n-2];
        for (int i = 1; i < n-1; ++i) {
            dp[i][i] = nums[i-1] * nums[i] * nums[i+1];
        }
        
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i < n-k; ++i) {
                for (int j = i; j <= i+k; ++j) {
                    int left = (i == 0 ? 1 : nums[i-1]);
                    int right = (i+k == n-1 ? 1 : nums[i+k+1]);
                    if (j == i) dp[i][i+k] = max(nums[j]*left*right +  dp[j+1][i+k], dp[i][i+k]);
                    else if (j == i+k) dp[i][i+k] = max(nums[j]*left*right + dp[i][j-1], dp[i][i+k]);
                    else dp[i][i+k] = max(nums[j]*left*right + dp[i][j-1] + dp[j+1][i+k], dp[i][i+k]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};