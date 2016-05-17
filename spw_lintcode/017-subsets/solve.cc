/**
 * Problem: Given a set of distinct integers, return all possible subsets.
 * Solve: bit operation.
 * Tips: using int to hold cnt is large enough, or we will not have enough
 *       memory space to hold ans
 */
class Solution {
    public:
        /**
         * @param S: A set of numbers.
         * @return: A list of lists. All valid subsets.
         */
        vector<vector<int> > subsets(vector<int> &nums) {
            int n = nums.size();

            vector<vector<int>> ans;
            int cnt = 1 << n;
            for (int i = 0; i < cnt; ++i) {
                vector<int> now;
                int j = i, pos = 0;
                while (j) {
                    if (j & 0x1) {
                        now.push_back(nums[pos]);
                    }

                    ++pos;
                    j >>= 1;
                }
                ans.push_back(now);
            }

            return ans;
        }
};
