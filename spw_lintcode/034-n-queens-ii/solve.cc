/**
 * Problem: Follow up for N-Queens problem.
 *          Now, instead outputting board configurations, return the total
 *          number of distinct solutions.
 * Solve: dfs
 * Tips: 1. judge if a place can be placed: opposite angles of a square
 */
class Solution {
    public:
        /**
         * Calculate the total number of distinct N-Queen solutions.
         * @param n: The number of queens.
         * @return: The total number of distinct solutions.
         */
        int totalNQueens(int n) {
            int ans = 0;

            vector<int> flag(n, 0);
            for (int j = 0; j < n; ++j) {
                dfs(ans, 0, j, flag);
            }

            return ans;
        }

        void dfs(int &ans, int level, int j, vector<int> &flag) {
            int n = flag.size();
            flag[level] = j;

            if (level == n-1) {
                ++ans;
                return;
            }

            for (int i = 0; i < n; ++i) {
                if (canPlace(level+1, i, flag)) {
                    dfs(ans, level+1, i, flag);
                }
            }
        }

        bool canPlace(int i, int j, vector<int> &flag) {
            for (int ii = 0; ii < i; ++ii) {
                if (flag[ii] == j || abs(i-ii) == abs(j-flag[ii])) return false;
            }

            return true;
        }
};

