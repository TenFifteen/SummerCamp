/**
 * Problem: Given an array consisting of n integers, find the contiguous
 *          subarray of given length k that has the maximum average value.
 *          And you need to output the maximum average value.
 * Solve: slide window
 * Tips: long long
 */
class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            int pos = 0;
            long long sum = 0, maxSum = 0;
            while (pos < k) sum += nums[pos++];

            maxSum = sum;
            while (pos < nums.size()) {
                sum -= nums[pos-k];
                sum += nums[pos];

                maxSum = max(sum, maxSum);
                ++pos;
            }

            return (double)maxSum / k;
        }
};
