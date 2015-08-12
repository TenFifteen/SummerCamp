/*
题目大意：
给定一个二维的01矩阵，1代表陆地，0代表海洋，问一共有多少岛屿

解题思路：
深搜

遇到的问题：
没有问题
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