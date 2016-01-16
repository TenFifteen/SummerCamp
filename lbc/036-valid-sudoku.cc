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