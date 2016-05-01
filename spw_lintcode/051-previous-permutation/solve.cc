/**
 * Problem: Given a list of integers, which denote a permutation.
 *          Find the previous permutation in ascending order.
 * Solve: find a ascending order sequence.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: An array of integers
         * @return: An array of integers that's previous permuation
         */
        vector<int> previousPermuation(vector<int> &nums) {
            int n = nums.size(), i = n - 2;
            while (i >= 0 && nums[i] <= nums[i+1]) --i;

            if (i >= 0) {
                int j = n - 1;
                while (j > i && nums[j] >= nums[i]) --j;

                swap(nums[i], nums[j]);
            }
            reverse(nums.begin()+i+1, nums.end());

            return nums;
        }
};
