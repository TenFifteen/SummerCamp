/**
 * Problem: Given a sorted positive integer array nums and an integer n,
 *          add/patch elements to the array such that any number in range [1, n]
 *          inclusive can be formed by the sum of some elements in the array.
 *          Return the minimum number of patches required.
 * Solve: greedy.
 *        The most optimal way is: 1 2 4 8 16 32... to represent all numbers, that is
 *        every bit's weight in binary representation.
 *        Proof: we must have 1 for the first, then use induction:
 *               if we can represent all sum in [1, miss), then we can add number 'num' to
 *               represent [1, miss+num) which will be largest when num = miss.
 *
 * Tips: miss must be long or will be overflow.
 *       the loop condition must be miss <= n, because we have [1, miss) every time.
 */
class Solution {
    public:
        int minPatches(vector<int>& nums, int n) {
            long long miss = 1, patch = 0, i = 0;

            while (miss <= n) {
                if (i < nums.size() && nums[i] <= miss) {
                    miss += nums[i++];
                } else {
                    patch++;
                    miss = miss * 2;
                }
            }
            return patch;

        }

};
