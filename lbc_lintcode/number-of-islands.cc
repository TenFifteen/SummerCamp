/*
题目：19 % 岛屿的个数 容易

题目大意：
给定一个二维的表格，true表示陆地，false表示海洋。问一共有多少块陆地

解题思路：
搜索

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int ret = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    ret++;
                    sub(grid, i, j);
                }
            }
        }
        return ret;
    }
    
    int sub(vector<vector<bool>> &grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == false) return 0;
        int ret = 1;
        grid[x][y] = false;
        ret += sub(grid, x-1, y);
        ret += sub(grid, x, y-1);
        ret += sub(grid, x+1, y);
        ret += sub(grid, x, y+1);
        return ret;
    }
};
