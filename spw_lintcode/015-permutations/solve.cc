/**
 * Problem: Given a list of numbers, return all possible permutations.
 * Solve: swap and recursive.
 * Tips: 1. use n to control the scale every time in the subroutine.
 *       2. when the nums is emtpy. return directly
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers.
         * @return: A list of permutations.
         */
        vector<vector<int> > permute(vector<int> nums) {
            vector<vector<int>> ans;
            if (nums.size() == 0) return ans;

            sub(ans, nums, nums.size());
            return ans;
        }

        void sub(vector<vector<int>> &ans, vector<int> &nums, int n) {
            if (n == 1) {
                ans.push_back(nums);
                return;
            }

            for (int i = 0; i < n; ++i) {
                swap(nums[i], nums[n-1]);
                sub(ans, nums, n-1);
                swap(nums[i], nums[n-1]);
            }
        }
};

