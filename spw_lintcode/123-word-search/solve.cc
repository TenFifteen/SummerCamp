/**
 * Problem: Given a 2D board and a word, find if the word exists in the grid.
 *          The word can be constructed from letters of sequentially adjacent cell,
 *          where "adjacent" cells are those horizontally or vertically neighboring.
 *          The same letter cell may not be used more than once.
 * Solve: simple dfs
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param board: A list of lists of character
         * @param word: A string
         * @return: A boolean
         */
        bool ans;
        bool exist(vector<vector<char> > &board, string word) {
            ans = false;
            int m = board.size(), n = board[0].size();

            vector<vector<bool>> used(m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    dfs(board, used, word, i, j, 0);
                    if (ans) return true;
                }
            }

            return false;
        }

        void dfs(vector<vector<char> > &board, vector<vector<bool> > &used, string word, int i, int j, int pos) {
            if (ans || pos == word.size()) {
                ans = true;
                return;
            }

            int m = board.size(), n = board[0].size();
            if (i < 0 || i >= m || j < 0 || j >= n || used[i][j] || board[i][j] != word[pos]) return;

            used[i][j] = true;

            dfs(board, used, word, i+1, j, pos+1);
            dfs(board, used, word, i-1, j, pos+1);
            dfs(board, used, word, i, j+1, pos+1);
            dfs(board, used, word, i, j-1, pos+1);
            used[i][j] = false;
        }
};
