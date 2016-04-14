/**
 * Problem: Given an array with n objects colored red, white or blue,
 *          sort them so that objects of the same color are adjacent,
 *          with the colors in the order red, white and blue.
 *          Here, we will use the integers 0, 1, and 2 to represent
 *          the color red, white, and blue respectively.
 * Solve: three partition
 * Tips: the while condition must be k <= r instead of k < r.
 *       because r point to the number who is the place before 2
 */
class Solution{
    public:
        /**
         * @param nums: A list of integer which is 0, 1 or 2
         * @return: nothing
         */
        void sortColors(vector<int> &nums) {
            int n = nums.size();

            int l = 0, r = nums.size()-1, k = 0;

            while (k <= r) {
                if (nums[k] == 0) {
                    swap(nums[k++], nums[l++]);
                } else if (nums[k] == 1) {
                    ++k;
                } else {
                    swap(nums[k], nums[r--]);
                }
            }
        }
};
