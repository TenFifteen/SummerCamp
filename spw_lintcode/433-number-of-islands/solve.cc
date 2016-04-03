/**
 * Problem: Given a boolean 2D matrix, find the number of islands.
 * Solve: dfs
 * Tips: no
 */
class Solution {
    public:
        void dfs(vector<vector<bool>> &grid, int x, int y, int dx[], int dy[]) {
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || !grid[x][y]) return;

            grid[x][y] = false;

            for(int i = 0; i < 4; ++i) {
                dfs(grid, x+dx[i], y+dy[i], dx, dy);
            }
        }
        /**
         * @param grid a boolean 2D matrix
         * @return an integer
         */
        int numIslands(vector<vector<bool>>& grid) {
            // Write your code here
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};

            int n = grid.size();
            if (n == 0) return 0;
            int m = grid[0].size();

            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j]) {
                        ans++;
                        dfs(grid, i, j, dx, dy);
                    }
                }
            }

            return ans;
        }
};
