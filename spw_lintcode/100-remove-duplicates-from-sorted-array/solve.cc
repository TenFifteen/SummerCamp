/**
 * Problem: Given a sorted array, remove the duplicates in place
 *          such that each element appear only once and return the new length.
 *
 *          Do not allocate extra space for another array,
 *          you must do this in place with constant memory.
 * Solve: previous number.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A: a list of integers
         * @return : return an integer
         */
        int removeDuplicates(vector<int> &nums) {
            int n = nums.size();
            if (n == 0) return 0;

            int index = 1, prev = nums[0];
            for (int i = 1; i < n; ++i) {
                if (nums[i] != prev) nums[index++] = nums[i];

                prev = nums[i];
            }

            return index;
        }
};
