/**
 * Problem: Given an integer array, find a subarray where the sum of numbers
 *          is zero. Your code should return the index of the first number
 *          and the index of the last number.
 * Solve: partial sum
 * Tips: the index when calculate the partial sum
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers
         * @return: A list of integers includes the index of the first number
         *          and the index of the last number
         */
        vector<int> subarraySum(vector<int> nums){
            vector<int> ans(2, 0);

            int n = nums.size();
            if (n == 0) return ans;

            vector<int> partSum(n+1, 0);
            for (int i = 1; i <= n; ++i)
                partSum[i] = partSum[i-1] + nums[i-1];

            unordered_map<int, int> index;
            for (int i = 0; i <= n; ++i) {
                if (index.find(partSum[i]) != index.end()) {
                    ans[0] = index[partSum[i]];
                    ans[1] = i - 1;
                    return ans;
                } else {
                    index[partSum[i]] = i;
                }
            }


            return ans;
        }
};
