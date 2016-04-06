/**
 * Problem: Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 *          Any live cell with two or three live neighbors lives on to the next generation.
 *          Any live cell with more than three live neighbors dies, as if by over-population..
 *          Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * Solve:  the key point is in place, because one integer can represent more than two state. Then we
 *         can certain do it in place.
 * Tips: Don't mistake about the m-poly and n-poly.
 */
class Solution {
    int count(vector<vector<int>> &board, int x, int y) {
        static int dn[] = {0, 1, 1, 1, 0, -1, -1, -1};
        static int dm[] = {1, 1, 0, -1, -1, -1, 0, 1};

        int cnt = 0;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < 8; ++i) {
            int tx = x + dm[i];
            int ty = y + dn[i];
            if (tx < 0 || tx > m-1 || ty < 0 || ty > n-1) continue;
            if (board[tx][ty] == 1 || board[tx][ty] == 3) ++cnt;
        }

        return cnt;
    }
    public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = count(board, i, j);
                if (board[i][j] == 1) {
                    if (cnt < 2 || cnt > 3) board[i][j] = 3;
                } else {
                    if (cnt == 3) board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = count(board, i, j);
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
    }
};
