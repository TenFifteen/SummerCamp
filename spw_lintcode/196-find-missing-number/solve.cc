/**
 * Problem: Given an array contains N numbers of 0 .. N,
 *          find which number doesn't exist in the array.
 * Solve: bit sum
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: a vector of integers
         * @return: an integer
         */
        int findMissing(vector<int> &nums) {
            // write your code here
            int realSum = 0;
            int allSum = 0;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                realSum ^= nums[i];
                allSum ^= i;
            }

            return allSum ^ n ^ realSum;
        }
};
