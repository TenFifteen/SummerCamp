/*
题目大意：
给定一个sudoku的棋盘，问是否是合理的

解题思路：
见代码。

遇到的问题：
一开始忘了考虑'.'这种了，结果就是rte
*/
class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            vector<bool> col(9, false), row(9, false), grid(9, false);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (col[board[i][j]-'1']) return false;
                    col[board[i][j]-'1'] = true;
                }
                    
                if (board[j][i] != '.') {
                    if (row[board[j][i]-'1']) return false;
                    row[board[j][i]-'1'] = true;
                }
                
                int x = i/3*3+j/3, y = i%3*3+j%3;
                if (board[x][y] != '.') {
                    if (grid[board[x][y]-'1']) return false;
                    grid[board[x][y]-'1'] = true;
                }
            }
        }
        
        return true;
    }
};