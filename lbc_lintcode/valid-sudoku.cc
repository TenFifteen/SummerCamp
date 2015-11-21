/*
题目：27 % 判断数独是否合法 容易

题目大意：
给定一个放置了一部分数字的数独表格，问是否是合理的。

解题思路：
就是个大水题。直接用hash

遇到的问题：
一开始忘记了考虑'.'了。
*/
class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        unordered_set<char> us;
        for (int i = 0; i < 9; ++i) {
            us.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (us.find(board[i][j]) != us.end()) return false;
                us.insert(board[i][j]);
            }
            us.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;
                if (us.find(board[j][i]) != us.end()) return false;
                us.insert(board[j][i]);
            }
            us.clear();
            int x = i/3*3;
            int y = i%3*3;
            for (int xx = x; xx < 3+x; ++xx) {
                for (int yy = y; yy < 3+y; ++yy) {
                    if (board[xx][yy] == '.') continue;
                    if (us.find(board[xx][yy]) != us.end()) return false;
                    us.insert(board[xx][yy]);
                }
            }
        }
        
        return true;
    }
};
