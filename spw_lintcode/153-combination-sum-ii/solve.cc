/**
 * Problem: Given a collection of candidate numbers (C) and a target number (T),
 *          find all unique combinations in C where the candidate numbers sums to T.
 *          Each number in C may only be used once in the combination.
 * Solve: dfs
 * Tips: skip the duplicate number.
 */
class Solution {
    public:
        /**
         * @param num: Given the candidate numbers
         * @param target: Given the target number
         * @return: All the combinations that sum to target
         */
        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            sort(num.begin(), num.end());

            vector<vector<int>> ans;
            vector<int> pre;

            dfs(ans, pre, num, 0, target);
            return ans;
        }

        void dfs(vector<vector<int> > &ans, vector<int> &pre, vector<int> &num, int start, int left) {
            if (left == 0) {
                ans.push_back(pre);
                return;
            }

            int n = num.size();
            for (int i = start; i < n; ++i) {
                if (num[i] <= left) {
                    pre.push_back(num[i]);
                    dfs(ans, pre, num, i+1, left-num[i]);
                    pre.pop_back();

                    // skip in the same level, but in the recursive invoke,
                    // it will not miss the proper solution.
                    while (i+1 < n && num[i+1] == num[i]) ++i;
                } else {
                    break;
                }
            }
        }
};
