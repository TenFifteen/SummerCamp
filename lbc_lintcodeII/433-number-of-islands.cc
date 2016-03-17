/*
题目大意：
给定一个二维矩阵，true表示陆地，false表示水。一共有多少块陆地。

解题思路：
dfs

遇到的问题：
没有。
*/
class Solution {
    void dfs(vector<vector<bool>> &grid, int x, int y) {
        if (x < 0 || y < 0 
            || x >= grid.size() || y >= grid[0].size() 
            || grid[x][y] == false) 
            return;
            
        grid[x][y] = false;
            
        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; ++i) {
            dfs(grid, x+ix[i], y+iy[i]);
        }
    }
    
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == true) {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return cnt;
    }
};