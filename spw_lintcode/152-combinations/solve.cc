/**
 * Problem: Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * Solve: dfs
 * Tips: none
 */
class Solution {
    public:
        /**
         * @param n: Given the range of numbers
         * @param k: Given the numbers of combinations
         * @return: All the combinations of k numbers out of 1..n
         */
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int>> ans;
            vector<int> prev;

            dfs(ans, prev, 1, k, n);

            return ans;
        }

        void dfs(vector<vector<int>> &ans, vector<int> prev, int start, int k, int n) {
            if (k == 0) {
                ans.push_back(prev);
                return;
            }

            for (int i = start; i <= n; ++i) {
                prev.push_back(i);
                dfs(ans, prev, i+1, k-1, n);
                prev.pop_back();
            }
        }
};
