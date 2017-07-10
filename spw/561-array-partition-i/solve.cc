/**
 * Problem: Given an array of 2n integers, your task is to group these
 *          integers into n pairs of integer, say (a1, b1), (a2, b2), ...,
 *          (an, bn) which makes sum of min(ai, bi) for all i from 1 to
 *          n as large as possible.
 * Solve: sort and sum
 * Tips: no
 */
class Solution {
    public:
        int arrayPairSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            int n = nums.size() / 2;
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += nums[i<<1];
            }

            return sum;
        }
};
