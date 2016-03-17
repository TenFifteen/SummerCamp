/*
题目大意：
给定一个数组，求其中的两个子数组的总和最大，两个子数组不可以为空，而且不可以重叠。

解题思路：
见代码

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        vector<int> left(nums);
        
        int sum = nums[0], Max = sum;
        for (int i = 1; i < nums.size(); ++i) {
            if (sum > 0) sum += nums[i];
            else sum = nums[i];
            Max = max(sum, Max);
            
            left[i] = Max;
        }
        
        sum = nums.back(), Max = sum;
        int ans = sum + left[nums.size()-2];
        for (int i = nums.size()-2; i > 0; --i) {
            if (sum > 0) sum += nums[i];
            else sum = nums[i];
            Max = max(Max, sum);
            
            ans = max(ans, Max + left[i-1]);
        }
        
        return ans;
    }
};
