/**
 * Problem: Given a sequence of integers, find the longest increasing subsequence (LIS).
 *          You code should return the length of the LIS.
 * Solve: use a vector to maintain a longest distance we have reach. And replace the first
 *        large one each time to make we can go even further in the future.
 * Tips: the binary search use the form that: traversal all possible cases: (condition must
 *       be that <=) and update the answer variable
 */
class Solution {
    public:
        int findIndex(vector<int> &s, int target) {
            int left = 0, right = s.size() - 1;

            int ans = s.size();
            while (left <= right) {
                int mid = (left + right) / 2;
                if (s[mid] <= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                    ans = min(ans, mid);
                }
            }

            return ans;
        }
        /**
         * @param nums: The integer array
         * @return: The length of LIS (longest increasing subsequence)
         */
        int longestIncreasingSubsequence(vector<int> nums) {
            int n = nums.size();
            vector<int> s;
            for (int i = 0; i < n; ++i) {
                int index = findIndex(s, nums[i]);
                if (index == s.size()) s.push_back(nums[i]);
                else s[index] = nums[i];
            }

            return s.size();
        }
};

