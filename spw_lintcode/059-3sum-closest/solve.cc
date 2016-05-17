/**
 * Problem: Given an array S of n integers, find three integers in S
 *          such that the sum is closest to a given number, target.
 *          Return the sum of the three integers.
 * Solve: sort + two pointers.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param numbers: Give an array numbers of n integer
         * @param target: An integer
         * @return: return the sum of the three integers, the sum closest target.
         */
        int threeSumClosest(vector<int> nums, int target) {
            sort(nums.begin(), nums.end());

            int n = nums.size();
            if (n < 3) return target;
            int ans = nums[0] + nums[1] + nums[2];
            for (int i = 0; i < n; ++i) {
                int left = i+1, right = n-1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == target) return sum;

                    if (abs(sum-target) < abs(ans-target)) ans = sum;
                    if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }

            return ans;
        }
};
