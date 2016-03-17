/*
题目大意：
给定一个数组，找到数组的k个区间，使得这k个区间的总和最大。区间至少有一个元素。

解题思路：
动归
n*n*k

遇到的问题：
一开始没有注意到每个区间必须有一个数这个条件，而且是必须是正好k个区间。
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
        if (nums.size() == 0) return 0;
        int n = nums.size();
        
        vector<int> dp(n+1, 0);
        for (int m = 1; m <= k; ++m) {
            for (int i = n; i >= m; --i) {
                int sum = 0, Max = INT_MIN;
                dp[i] = INT_MIN;
                
                for (int j = i-1; j >= m-1; --j) {
                    if (sum > 0) sum += nums[j];
                    else sum = nums[j];
                    Max = max(Max, sum);
                    
                    dp[i] = max(dp[i], dp[j]+Max);
                }
            }
        }
        
        return dp[n];
    }
};
