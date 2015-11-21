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
