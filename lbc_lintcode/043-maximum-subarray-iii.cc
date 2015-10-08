/*
题目：21 % 最大子数组 III 困难

题目大意：
给定一个数组，求其k的不重叠的字段和的和的最大值。

解题思路：
动态规划

遇到的问题：
动态规划的参数调整比较难受，所以要明明白白的写清楚转移方程再写代码

*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        vector<vector<int>> buf(nums.size(), vector<int>(nums.size()));
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            int maxsum = cur;
            buf[i][i] = cur;
            for (int j = i+1; j < nums.size(); ++j) {
                if (cur > 0) cur += nums[j];
                else cur = nums[j];
                if (maxsum < cur) maxsum = cur;
                buf[i][j] = maxsum;
            }
        }
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(k+1, 0));
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                int max = dp[i-1][j-1] + nums[i-1];
                for (int m = i-2; m >= j-1; --m) {
                    if (dp[m][j-1] + buf[m][i-1] > max) {
                        max = dp[m][j-1] + buf[m][i-1];
                    }
                }
                dp[i][j] = max;
            }
        }
        return dp[nums.size()][k];
    }
};

