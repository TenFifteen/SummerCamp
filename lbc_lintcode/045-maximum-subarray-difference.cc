/*
题目：23 % 最大子数组差 中等

题目大意：
求两个不重叠的区间，其区间和的差的绝对值最大。

解题思路：
分别从前往后和从后往前求最大字段和和最小字段和，然后就可以求出绝对值的最大

遇到的问题：
一开始只是求出了左边的最大值，和右边的最小值。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        vector<int> left_max(nums.size()), left_min(nums.size());
        left_max[0] = nums[0];
        left_min[0] = nums[0];
        int cur_max = nums[0], cur_min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cur_max > 0) {
                cur_max += nums[i];
            } else {
                cur_max = nums[i];
            }
            if (cur_max >= left_max[i-1]) {
                left_max[i] = cur_max;
            } else {
                left_max[i] = left_max[i-1];
            }
            
            if (cur_min < 0) {
                cur_min += nums[i];
            } else {
                cur_min = nums[i];
            }
            if (cur_min < left_min[i-1]) {
                left_min[i] = cur_min;
            } else {
                left_min[i] = left_min[i-1];
            }
        }
        cur_max = cur_min = nums[nums.size()-1];
        int right_max = cur_max, right_min = cur_min;
        int ret = max(abs(left_max[nums.size()-2]-cur_min), abs(left_min[nums.size()-2]-cur_max));
        for (int i = nums.size()-2; i > 0; --i) {
            if (cur_min < 0) {
                cur_min += nums[i];
            } else {
                cur_min = nums[i];
            }
            if (cur_min < right_min) {
                right_min = cur_min;
            }
            if (abs(right_min - left_max[i-1]) > ret) {
                ret = abs(left_max[i-1] - right_min);
            }
            
            if (cur_max > 0) {
                cur_max += nums[i];
            } else {
                cur_max = nums[i];
            }
            if (cur_max > right_max) {
                right_max = cur_max;
            }
            if (abs(right_max-left_min[i-1]) > ret) {
                ret = abs(right_max-left_min[i-1]);
            }
        }
        return ret;
    }
};

