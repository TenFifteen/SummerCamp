/**
 * Problem: Print numbers from 1 to the largest number with N digits by recursion.
 * Solve: backtrack
 * Tips: don't print 0
 */
class Solution {
    public:
        void dfs(vector<int> &ans, int prefix, int d, int n) {
            if (d == n) {
                if (prefix) ans.push_back(prefix);
                return;
            }

            prefix *= 10;
            for (int i = 0; i < 10; ++i) {
                dfs(ans, prefix+i, d+1, n);
            }
        }
        /**
         * @param n: An integer.
         * return : An array storing 1 to the largest number with n digits.
         */
        vector<int> numbersByRecursion(int n) {
            vector<int> ans;

            if (n < 1) return ans;
            dfs(ans, 0, 0, n);

            return ans;
        }
};
