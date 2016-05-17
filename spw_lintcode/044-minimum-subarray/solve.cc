/**
 * Problem: Given an array of integers, find the subarray with smallest sum.
 *         Return the sum of the subarray.
 * Solve: dp
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: a list of integers
         * @return: A integer denote the sum of minimum subarray
         */
        int minSubArray(vector<int> nums) {
            int n = nums.size();
            if (n <= 0) return 0;

            int ans = nums[0], dp = 0;
            for (int i = 0; i < n; ++i) {
                dp = min(nums[i], dp+nums[i]);
                ans = min(ans, dp);
            }

            return ans;
        }
};
