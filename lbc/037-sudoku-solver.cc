/*
题目大意：
给一个填了一部分的sudoku，解出来。

解题思路：
深搜，回溯。

遇到的问题：
无问题。
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> tmp(9, 0);
        vector<vector<int>> row(9,tmp), col(9,tmp), grid(9,tmp);
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.')continue;
                int cur = board[i][j]-'1';
                row[i][cur] = 1;
                col[j][cur] = 1;
                grid[i/3*3+j/3][cur] = 1;
            }
        }
        sub(board, row, col, grid, 0, 0);
    }
    
    bool sub(vector<vector<char>> &board, vector<vector<int>> &row, vector<vector<int>> &col, vector<vector<int>> &grid, int x, int y){
        if(y == 9){
            if(x == 8)return true;
            x++;
            y = 0;
        }
        if(board[x][y] != '.')return sub(board, row, col, grid, x, y+1);
        bool ret = false;
        for(int i = 0; i < 9; ++i){
            if(row[x][i] || col[y][i] || grid[x/3*3+y/3][i])continue;
            board[x][y] = '1'+i;
            row[x][i] = 2;
            col[y][i] = 2;
            grid[x/3*3+y/3][i] = 2;
            ret |= sub(board, row, col, grid, x, y+1);
            if(ret)return true;
            board[x][y] = '.';
            row[x][i] = 0;
            col[y][i] = 0;
            grid[x/3*3+y/3][i] = 0;
        }
        return ret;
    }
};