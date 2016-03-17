/**
 * Problem: Given an array of numbers nums, in which exactly
 *          two elements appear only once and all the other
 *          elements appear exactly twice. Find the two elements
 *          that appear only once.
 * Solve: find a XOR result, then the diff must contain a bit 1, because
 *        There are two distinct numbers. Then use the diff to
 *        cut the set into two set. Then we can convert the question
 *        to two same problem: only contain one number that occur only
 *        once.
 * Tips: no
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int num : nums) {
            diff ^= num;
        }
        diff &= -diff;

        vector<int> ans = {0, 0};
        for (int num : nums) {
            if ((diff & num) == 0) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }

        return ans;
    }
};
