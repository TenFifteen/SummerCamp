/*
题目大意：
给一个填了一部分的sudoku，解出来。

解题思路：
深搜，回溯。

遇到的问题：
无问题。

再次阅读：
看了题目之后还是感觉应该是一个深搜+回溯的题目。
看完了DISCUSS，感觉这样已经足够好了。
但是写代码的时候可以写的各种函数封装的更好一些。
例如，下面的代码写的就很好：
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        util(board, 0);
    }
    bool util(vector<vector<char>>& board, int pos)
    {
        if (pos >= 81)
            return true;
        int i = pos / 9;
        int j = pos % 9;
        if (board[i][j] != '.')
            return util(board, pos + 1);
        else
        {
            for (char c = '1'; c <= '9'; c++)
            {
                if (!isInRow(board, i,c) && !isInCol(board, j, c) && !isInRec(board, i, j, c))
                {
                    board[i][j] = c;
                    if (util(board, pos + 1))
                        return true;
                    else
                        board[i][j] = '.';
                }
            }
            return false;
        }
    }

    bool isInRow(vector<vector<char>>& board, int i, char c)
    {
        vector<char>& row = board[i];
        for (int k = 0; k < 9; k++)
        {
            if (row[k] == c)
                return true;
        }
        return false;
    }
    bool isInCol(vector<vector<char>>& board,int j, char c)
    {
        for (int k = 0; k < 9; k++)
        {
            if (board[k][j] == c)
                return true;
        }
        return false;
    }
    bool isInRec(vector<vector<char>>& board, int i, int j, char c)
    {
        int bigrow = i / 3, bigcol = j / 3;
        for (int m = 3 * bigrow; m < 3 * (bigrow + 1); m++)
        {
            for (int n = 3 * bigcol; n < 3 * (bigcol + 1); n++)
                if (board[m][n] == c)
                    return true;
        }
        return false;
    }
};
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