/**
 * Problem: Given a 2D board and a word, find if the word exists in the grid.
 * Solve: dfs --> backtrace
 * Tips: how much the complexity is
 */
bool dfs(char **board, int boardRowSize, int boardColSize, int i, int j, char *word, int now) {
    if (i >= boardRowSize || i < 0 || j >= boardColSize || j < 0 || board[i][j] == '\0' || board[i][j] != word[now]) return false;

    if (word[now+1] == '\0') {
        return true;

    }
    char t = board[i][j];
    board[i][j] = '\0';
    if (dfs(board, boardRowSize, boardColSize, i+1, j, word, now+1) || dfs(board, boardRowSize, boardColSize, i-1, j, word, now+1)
            || dfs(board, boardRowSize, boardColSize, i, j+1, word, now+1) || dfs(board, boardRowSize, boardColSize, i, j-1, word, now+1))
        return true;
    board[i][j] = t;
    return false;

}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int i, j;

    if (strlen(word) == 0) return false;
    for (i = 0; i < boardRowSize; ++i) {
        for (j = 0; j < boardColSize; ++j) {
            if (dfs(board, boardRowSize, boardColSize, i, j, word, 0))
                return true;

        }

    }

    return false;

}
class Solution {
public:
    bool find = false;
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() <= 0) return false;
        if (word.size() == 0) return true;

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, used, word, i, j, 0);
                if (find) return true;
            }
        }

        return false;
    }

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &used, string &word, int y, int x, int pos) {
        if (pos == word.size() || find) {
            find = true;
            return;
        }

        int m = board.size(), n = board[0].size();
        static int dx[] = {0, 1, 0, -1};
        static int dy[] = {1, 0, -1, 0};

        if (y < 0 || y >= m || x < 0 || x >= n || used[y][x] || board[y][x] != word[pos]) return;


        used[y][x] = true;
        for (int i = 0; i < 4; ++i) {
            dfs(board, used, word, y+dy[i], x+dx[i], pos+1);
        }
        used[y][x] = false;

    }
};
