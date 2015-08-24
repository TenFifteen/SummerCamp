/*
题目：24 % 最大子数组 II 中等

题目大意：
求出两个不重叠的子数组的和最大

解题思路：
从前往后的求一遍，然后再从后往前的求一遍

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        int cur = nums[0], ret = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cur > 0) {
                cur += nums[i];
            } else {
                cur = nums[i];
            }
            if (cur > ret) {
                ret = cur;
            }
            ans[i] = ret;
        }
        cur = nums[nums.size()-1];
        ret = cur;
        int real_ret = cur + ans[nums.size()-2];
        for (int i = nums.size()-2; i > 0; --i) {
            if (cur > 0) {
                cur += nums[i];
            } else {
                cur = nums[i];
            }
            if (cur > ret) {
                ret = cur;
            }
            if (ret + ans[i-1] > real_ret) {
                real_ret = ret + ans[i-1];
            }
        }
        
        return real_ret;
    }
};

