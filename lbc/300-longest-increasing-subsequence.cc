/*
题目大意：
给定一个数组，求其最长上升子序列。

解题思路：
动归。
普通的动归是n*n的复杂度。
如果我们把每个最长的上升子序列的最后一个数字记录下来的话，可以用二分查找进行更新。
使得复杂度变为nlogn。

遇到的问题：
本来知道是有nlogn的方法的，可是自己还是没有想起来到底应该二分哪个东西。
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        
        vector<int> dp(nums.size());
        int len = 1;
        dp[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp[len-1]) {
                dp[len++] = nums[i];
            } else {
                int left = 0, right = len-1, index = len-1;
                while (left <= right) {
                    int mid = left + (right-left)/2;
                    if (dp[mid] >= nums[i]) {
                        index = min(index, mid);
                        right = mid-1;
                    } else {
                        left = mid+1;
                    }
                }
                dp[index] = nums[i];
            }
        }
        
        return len;
    }
};