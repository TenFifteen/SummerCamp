/**
 * Problem: Find the contiguous subarray within an array (containing
 *          at least one number) which has the largest product.
 * Solve: keep the maximal and minimal product end with nums[i]
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: a vector of integers
         * @return: an integer
         */
        int maxProduct(vector<int>& nums) {

            int n = nums.size();
            if (n == 0) return 0;


            int now = 1;
            int maxNow = nums[0], minNow = nums[0];
            int ans = nums[0];

            for (int i = 1; i < n; ++i) {
                int tmpMax = max(nums[i], max(maxNow * nums[i], minNow * nums[i]));
                int tmpMin = min(nums[i], min(maxNow * nums[i], minNow * nums[i]));

                ans = max(tmpMax, ans);
                maxNow = tmpMax, minNow = tmpMin;
            }

            return ans;
        }
};
