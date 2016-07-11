/**
 * Problem: Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * Solve: dfs + sort
 * Tips: no
 */
class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            vector<vector<int>> ans;
            vector<int> now;
            vector<bool> used(nums.size(), false);

            dfs(ans, nums, now, used);

            return ans;
        }

        void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &now, vector<bool> &used) {
            if (now.size() == nums.size()) {
                ans.push_back(now);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    now.push_back(nums[i]);

                    dfs(ans, nums,  now, used);

                    now.pop_back();
                    used[i] = false;
// inside judgement
                    while (i+1 < nums.size() && nums[i+1] == nums[i]) ++i;
                }

            }
        }
};
