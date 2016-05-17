/**
 * Problem: Given an array of integers, find two non-overlapping subarrays
 *          which have the largest sum. The number in each subarray should be contiguous.
 *          Return the largest sum.
 * Solve: use two array to store the left[0, i) and right[i, n)  subarray maximum
 *        sum. Then traversal and get the max result.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers
         * @return: An integer denotes the sum of max two non-overlapping subarrays
         */
        int maxTwoSubArrays(vector<int> nums) {
            int n = nums.size();
            if (n < 2) return 0;

            vector<int> left(n+1, 0), right(n+1, 0);

            int dp = 0; // initialized to 0 as the right edge
            // can't be initialized to 0.
            left[0] = nums[0];
            // left[i] max subarray sum of 0 ... i-1
            for (int i = 0; i < n; ++i) {
                dp = max(nums[i], nums[i]+dp);
                left[i+1] = max(left[i], dp);
            }

            dp = 0;
            right[n] = nums[n-1];
            // right[i] max subarray sum of i ... n-1
            for (int i = n-1; i >= 0; --i) {
                dp = max(nums[i], nums[i]+dp);
                right[i] = max(right[i+1], dp);
            }

            int ans = nums[0] + nums[n-1];
            for (int i = 1; i < n; ++i) {
                ans = max(ans, left[i]+right[i]);
            }

            return ans;
        }
};

