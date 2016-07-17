/**
 * Problem: Find the contiguous subarray within an array (containing
 *          at least one number) which has the largest sum.
 * Solve: dp
 * Tips: no.
 */
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            if (n < 1) return 0;

            int ans = nums[0], sumToNow = 0;
            for (int i = 0; i < n; ++i) {
                sumToNow = max(nums[i], sumToNow + nums[i]);
                ans = max(sumToNow, ans);
            }

            return ans;
        }
};
