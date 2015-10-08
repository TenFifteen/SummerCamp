/*
题目：37 % 最大子数组 容易

题目大意：
求最大的子数组的和

解题思路：
直接往前加，加到负了就直接去掉。这期间会求得最大值

遇到的问题：
题目要求中的最少有一个数没有考虑清楚。
*/
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        int cur = nums[0];
        int ret = cur;
        for (int i = 1; i < nums.size(); ++i) {
            if (cur > 0) {
                cur += nums[i];
            } else {
                cur = nums[i];
            }
            if (cur > ret) {
                ret = cur;
            }
        }
        return ret;
    }
};

