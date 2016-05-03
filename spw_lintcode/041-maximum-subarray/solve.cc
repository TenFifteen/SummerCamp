/**
 * Problem: Given an array of integers, find a contiguous subarray which has the largest sum.
 * Solve: dp
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers
         * @return: A integer indicate the sum of max subarray
         */
        int maxSubArray(vector<int> nums) {
            int n = nums.size();

            int ans = nums[0], dp = 0;
            for (int i = 0; i < n; ++i) {
                dp = max(nums[i], dp+nums[i]);
                ans = max(ans, dp);
            }

            return ans;
        }
};

