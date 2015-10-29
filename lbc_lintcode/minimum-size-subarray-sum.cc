/*
题目：23 % 和大于S的最小子数组 中等

题目大意：
给定一个数组，问能满足和大于s的最短的连续数组是多少？

解题思路：
两指针，维持一个区间

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        if (nums.size() == 0) return -1;
        int sum = nums[0];
        int ans = INT_MAX;
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (sum >= s) {
                if (right-left+1 < ans) {
                    ans = right-left+1;
                }
                sum -= nums[left];
                left++;
            } else {
                right++;
                if (right < nums.size()) {
                    sum += nums[right];
                }
            }
        }
        if (ans != INT_MAX) {
            return ans;
        } else {
            return -1;
        }
    }
};
