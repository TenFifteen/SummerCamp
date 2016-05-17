/**
 * Problem: Given a list of integers, which denote a permutation.
 *          Find the next permutation in ascending order.
 * Solve: find a fall from the end to the begin. Swap the one with
 *        the first number larger than it. Then the sequence after
 *        the number must be a non-ascending order. Then reverse it;
 * Tips: after swap. the sequence after the number must be in order.
 */
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        int n = nums.size();

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) --i;
        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
            // don't need sort here
        }

        reverse(nums.begin()+i+1, nums.end());
        return nums;
    }
};
