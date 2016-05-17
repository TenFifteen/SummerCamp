/**
 * Problem: Given an array of integers, find two numbers such that they add up to a specific target number.
 *          The function twoSum should return indices of the two
 *          numbers such that they add up to the target, where
 *          index1 must be less than index2. Please note that your
 *          returned answers (both index1 and index2) are NOT zero-based.
 * Solve: hash
 * Tips: no
 */
class Solution {
    public:
        /*
         * @param numbers : An array of Integer
         * @param target : target = numbers[index1] + numbers[index2]
         * @return : [index1+1, index2+1] (index1 < index2)
         */
        vector<int> twoSum(vector<int> &nums, int target) {
            vector<int> ans(2, 0);

            int n = nums.size();
            unordered_map<int, int> index;
            for (int i = 0; i < n; ++i) {
                int s = target - nums[i];
                if (index.find(s) == index.end()) {
                    index[nums[i]] = i;
                } else {
                    ans[0] = index[s] + 1;
                    ans[1] = i + 1;
                    return ans;
                }
            }

            return ans;
        }
};
