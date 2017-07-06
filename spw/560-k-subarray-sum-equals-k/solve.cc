/**
 * Problem: Given an array of integers and an integer k, you need
 *          to find the total number of continuous subarrays whose
 *          sum equals to k.
 * Solve: partialSum + hashtable
 * Tips: 1. pass one partial sum, minus its count;
 *       2. add cnt[0] first.
 */
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> cnt;
            int sum = 0, n = nums.size();
            vector<int> partialSum(n+1);
            for (int i = 0; i < n; ++i) {
                sum += nums[i];

                cnt[sum]++;
                partialSum[i+1] = sum;
            }

            int res = 0;
            cnt[0]++;
            for (int i = 0; i <= n; ++i) {
                int left = k + partialSum[i];
                cnt[partialSum[i]]--;

                if (cnt.find(left) != cnt.end()) {
                    res += cnt[left];
                }
            }

            return res;
        }
};
