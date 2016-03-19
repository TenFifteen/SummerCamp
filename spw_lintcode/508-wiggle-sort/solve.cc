/**
 * Problem: Given an unsorted array nums, reorder
 *          it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 * Solve: sort and swap
 * Tips: see comment below.
 */
class Solution {
    public:
        void swap(vector<int> &nums, int i, int j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        /**
         * @param nums a list of integer
         * @return void
         */
        void wiggleSort(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            int n = nums.size();
            int i;
            for (i = 1; i + 2 < n; i+=2) {
                swap(nums, i, i+2);
            }

            // i should > 1 to avoid there are
            // only two elements
            if (i == n-1 && i > 1) {
                swap(nums,  i-1, i);
            } else if (i == n-2) {
                swap(nums, i, i+1);
            }
        }
};
