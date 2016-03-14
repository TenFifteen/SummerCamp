/*
题目大意：
给定一个数组，问最小的子数组的和是多少？

解题思路：
跟最大的子数组和是一样的

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        
        int sum = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) sum += nums[i];
            else sum = nums[i];
            ans = min(ans, sum);
        }
        
        return ans;
    }
};
