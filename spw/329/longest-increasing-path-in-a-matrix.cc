/**
 * Problem: Given an integer matrix, find the length of the longest increasing path.
 *          From each cell, you can either move to four directions: left, right, up or down.
 *          You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 * Solve: dfs + memoization
 * Tips: 1. need not visited vector, because the dp matrix can let it return directly if the
 *          node has been visited.
 */
class Solution {
    private:
        int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int x, int y, int m, int n) {
            static int d[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            if (dp[x][y] != -1) return dp[x][y];

            int now = matrix[x][y];
            int ans = 1;
            for (int i = 0; i < 4; ++i) {
                int tx = x + d[i][1], ty = y + d[i][0];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || matrix[tx][ty] <= now) continue;

                ans = max(ans, dfs(matrix, dp, tx, ty, m, n)+1);
            }

            return dp[x][y] = ans;
        }
    public:
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            int m = matrix.size();
            if (m == 0) return 0;
            int n = matrix[0].size();

            int ans = 0;
            vector<vector<int>> dp(m, vector<int>(n, -1));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    ans = max(ans, dfs(matrix, dp, i, j, m, n));
                }
            }

            return ans;
        }
};
