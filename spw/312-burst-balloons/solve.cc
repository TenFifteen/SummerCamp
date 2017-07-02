/**
 * Problem: Given n balloons, indexed from 0 to n-1. Each balloon is painted with
 *          a number on it represented by array nums. You are asked to burst all
 *          the balloons. If the you burst balloon i you will get
 *          nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent
 *          indices of i. After the burst, the left and right then becomes adjacent.
 *
 *          Find the maximum coins you can collect by bursting the balloons wisely.
 * Solve: divide and conquer and use dp to optimize.
 *        First, only one element.
 *        Second, find the right state: every element as the last element, which partition
 *        the origin array to two sub ones. Then we can call itself and add in then end
 *        (nums[left-1] * nums[i] * nums[right+1]), because after call, the balloons in
 *        [left, i-1] and [i+1, right] disappear.
 *        When thinking the process, we can try a small dataset.
 *        Thirdly, use a memorized array to remember the intermedia results.
 * Tips: do not use static array as the intermedia array, because the sub function will
 *       be called many times by maxCoins, and the size varies.
 */
class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            nums.insert(nums.begin(), 1);
            nums.push_back(1);

            vector<vector<int>> interRes(nums.size(), vector<int>(nums.size(), 0));
            return sub(nums, 1, nums.size()-2, interRes);
        }

        int sub(vector<int> &nums, int left, int right,
                vector<vector<int>> &interRes) {
            if (right < left || left < 1 || right >= nums.size()) return 0;
            if (interRes[left][right] != 0) return interRes[left][right];

            int res = 0;
            for (int i = left; i <= right; ++i) {
                int part = sub(nums, left, i-1, interRes) +
                    sub(nums, i+1, right, interRes) +
                    nums[left-1]*nums[i]*nums[right+1];
                res = max(part, res);
            }

            return interRes[left][right] = res;
        }
};
