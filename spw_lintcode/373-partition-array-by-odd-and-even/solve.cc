/**
 * Problem: Partition an integers array into odd number first and even number second.
 * Solve: partition
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: a vector of integers
         * @return: nothing
         */
        void partitionArray(vector<int> &nums) {
            // write your code here

            int n = nums.size();

            int l = 0, r = n - 1;
            while (l < r) {
                while (l < r && nums[r] % 2 == 0) --r;
                while (l < r && nums[l] % 2 == 1) ++l;
                swap(nums[l], nums[r]);
            }
        }
};
