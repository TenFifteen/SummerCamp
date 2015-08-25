/*
题目：38 % 最小子数组 容易

题目大意：
寻找一个子数组，其和最小

解题思路：
跟最大子数组和的道理是一样的

遇到的问题：
没有问题。
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
        int ret = nums[0], cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cur < 0) {
                cur += nums[i];
            } else {
                cur = nums[i];
            }
            if (cur < ret) {
                ret = cur;
            }
        }
        return ret;
    }
};

