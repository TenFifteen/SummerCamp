/**
 * Problem: The n-queens puzzle is the problem of placing n queens on an
 *          n×n chessboard such that no two queens attack each other.
 *          Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 *          Each solution contains a distinct board configuration of the n-queens'
 *          placement, where 'Q' and '.' both indicate a queen and an empty space respectively.'
 * Solve: dfs
 * Tips: no
 */
class Solution {
    public:
        /**
         * Get all distinct N-Queen solutions
         * @param n: The number of queens
         * @return: All distinct solutions
         * For example, A string '...Q' shows a queen on forth position
         */
        vector<vector<string> > solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<int> flag(n, 0);
            for (int j = 0; j < n; ++j) {
                dfs(ans, 0, j, flag);
            }

            return ans;
        }

        void dfs(vector<vector<string>> &ans, int level, int j, vector<int> &flag) {
            int n = flag.size();
            flag[level] = j;

            if (level == n-1) {
                ans.push_back(getSol(flag));
                return;
            }

            for (int i = 0; i < n; ++i) {
                if (canPlace(level+1, i, flag)) {
                    dfs(ans, level+1, i, flag);
                }
            }
        }

        vector<string> getSol(vector<int> &flag) {
            int n = flag.size();
            string tmp(n, '.');
            vector<string> ans(n, tmp);

            for (int i = 0; i < n; ++i) {
                ans[i][flag[i]] = 'Q';
            }

            return ans;
        }

        bool canPlace(int i, int j, vector<int> &flag) {
            int sum = i + j, sub = i - j;
            for (int ii = 0; ii < i; ++ii) {
                if (flag[ii] == j || ii+flag[ii] == sum || ii-flag[ii] == sub) return false;
            }

            return true;
        }
};

