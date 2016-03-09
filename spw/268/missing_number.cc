/**
 * Problem: Given an array containing n distinct numbers taken
 *          from 0, 1, 2, ..., n, find the one that is missing
 *          from the array.
 * Solve: bit sum
 * Tips: no
 */
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();

            int sum = 0;
            int t = 0;
            for (int i = 0; i < n; ++i) {
                t ^= i;
                sum ^= nums[i];

            }

            return t ^ n ^ sum;

        }

};
