/**
 * Problem: Determine whether a Sudoku is valid.
 * Solve: three matrix flag
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param board: the board
         * @return: wether the Sudoku is valid
         */
        bool isValidSudoku(const vector<vector<char>>& board) {
            bool row[9][9] = {false};
            bool col[9][9] = {false};
            bool grid[9][9] = {false};

            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] != '.') {
                        int pos = (i / 3) * 3 + j / 3;
                        int num = board[i][j] - '1';

                        if (row[i][num] || col[j][num] || grid[pos][num]) return false;

                        row[i][num] = true;
                        col[j][num] = true;
                        grid[pos][num] = true;
                    }
                }
            }

            return true;
        }
};
