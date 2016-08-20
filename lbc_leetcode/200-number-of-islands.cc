/*
题目大意：
给定一个二维的01矩阵，1代表陆地，0代表海洋，问一共有多少岛屿

解题思路：
深搜

遇到的问题：
没有问题

再次阅读：
就是一个深搜，没有更好的办法了。
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    ret++;
                    sub(grid, i, j);
                }
            }
        }
        return ret;
    }

    void sub(vector<vector<char>> &grid, int x, int y){
        if(grid[x][y] == '0')return;
        grid[x][y] = '0';
        if(x > 0)sub(grid, x-1, y);
        if(y > 0)sub(grid, x, y-1);
        if(x+1 < grid.size())sub(grid, x+1, y);
        if(y+1 < grid[0].size())sub(grid, x, y+1);
    }
};
/*
第二次做：
一气呵成，很好。
*/
class Solution {
private:
    void dfs(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1') return;

        grid[x][y] = '2';

        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; ++i) {
            dfs(grid, x+ix[i], y+iy[i]);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int m = grid.size(), n = grid[0].size();
        int total = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    total++;
                    dfs(grid, i, j);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '2') grid[i][j] = '1';
            }
        }

        return total;
    }
};
/*
 * good
 */
class Solution {
private:
    void dfs(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return;
        if (grid[x][y] == '0') return;

        grid[x][y] = '0';
        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; ++i) {
            dfs(grid, x + ix[i], y + iy[i]);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
