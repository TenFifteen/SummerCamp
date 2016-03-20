/**
 * Problem: Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *          A region is captured by flipping all 'O''s into 'X''s in that surrounded region.
 * Solve: dfs from the boarder change all 'O' to 'A', then the other Os are all the ones that
 *        be surrounded.
 * Tips: no
 */
class Solution {
    public:
        void dfs(vector<vector<char>> &board, int i, int j, int *dx, int *dy) {
            int m = board.size(), n = board[0].size();

            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

            board[i][j] = 'A';

            for (int k = 0; k < 4; ++k) {
                dfs(board, i+dx[k], j+dy[k], dx, dy);
            }
        }

        void fromTo(vector<vector<char> > &board, char from, char to) {
            int m = board.size(), n = board[0].size();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == from) board[i][j] = to;
                }
            }
        }

        /**
         * @param board a 2D board containing 'X' and 'O'
         * @return void
         */
        void surroundedRegions(vector<vector<char>>& board) {
            if (board.size() == 0) return;

            // Write your code here
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};

            int m = board.size(), n = board[0].size();
            for (int i = 0; i < m; ++i) {
                dfs(board, i, 0, dx, dy);
                dfs(board, i, n-1, dx, dy);
            }

            for (int i = 0; i < n; ++i) {
                dfs(board, 0, i, dx, dy);
                dfs(board, m-1, i, dx, dy);
            }

            fromTo(board, 'O', 'X');
            fromTo(board, 'A', 'O');
        }
};
