/*
题目：25 % 最长上升子序列 中等

题目大意：
给定一个数组，求其中的最长上升子序列

解题思路：
动态规划

遇到的问题：
题中说可以有nlogn的算法

精彩解答：
http://www.cnblogs.com/liyukuneed/archive/2013/05/26/3090402.html
*/
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if (nums.size() < 2) return nums.size();
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] <= nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    if (dp[i] > ans) {
                        ans = dp[i];
                    }
                }
            }
        }
        return ans;
    }
};

