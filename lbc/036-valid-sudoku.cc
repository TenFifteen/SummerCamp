/*
题目大意：
给出一个sudoku的表格，判断当前情况是否是符合条件的。

解题思路：
用hash直接记录每一部分的值，如果有冲突就是不符合条件的。

遇到的问题：
一次通过。

再次阅读：
之前的做法应该是没有任何问题，但是可以将set改为unordered_set，这样就可以做到n*n的
复杂度了。
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9), col(9),grid(9);
        for(int i = 0;i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.')continue;
                if(row[i].count(board[i][j])){
                    return false;
                }else{
                    row[i].insert(board[i][j]);
                }
                if(col[j].count(board[i][j])){
                    return false;
                }else{
                    col[j].insert(board[i][j]);
                }
                if(grid[i/3*3 + j/3].count(board[i][j])){
                    return false;
                }else{
                    grid[i/3*3 + j/3].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
/*
第二次做：
非常简单的一道题，这次是为了降低空间复杂度，将其拆成了三个循环了。
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            vector<bool> flag(9, false);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (flag[board[i][j]-'1']) return false;
                    flag[board[i][j]-'1'] = true;
                }
            }
        }
        
        for (int i = 0; i < 9; ++i) {
            vector<bool> flag(9, false);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (flag[board[j][i]-'1']) return false;
                    flag[board[j][i]-'1'] = true;
                }
            }
        }
        
        for (int i = 0; i < 9; ++i) {
            int x = i / 3, y = i % 3;
            vector<bool> flag(9, false);
            for (int j = 0; j < 9; ++j) {
                int xx = x * 3 + j / 3;
                int yy = y * 3 + j % 3;
                if (board[xx][yy] != '.') {
                    if (flag[board[xx][yy]-'1']) return false;
                    flag[board[xx][yy]-'1'] = true;
                }
            }
        }
        
        return true;
    }
};