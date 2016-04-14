/**
 * Problem: Given a set of candidate numbers (C) and a target number (T), find all unique
 *          combinations in C where the candidate numbers sums to T.
 *          The same repeated number may be chosen from C unlimited number of times.
 * Solve: dfs
 * Tips: how to handle the duplicates
 */
class Solution {
    public:
        /**
         * @param candidates: A list of integers
         * @param target:An integer
         * @return: A list of lists of integers
         */
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int>> ans;
            vector<int> pre;

            sort(candidates.begin(), candidates.end());
            dfs(ans, candidates, pre, 0, target);

            return ans;
        }

        void dfs(vector<vector<int> > &ans, vector<int> &candidates, vector<int> pre, int i, int left) {
            if (left == 0) {
                ans.push_back(pre);
                return;
            }

            if (i == candidates.size()) return;

            // take care about the statement sequence.
            int now = 0;
            while (now <= left) {
                dfs(ans, candidates, pre, i+1, left-now);

                pre.push_back(candidates[i]);
                now += candidates[i];
            }
        }
};
