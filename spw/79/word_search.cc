#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

/**
 * Time Exceeded
 */
bool ans = false;
void dfs(bool **flag, char **board, int boardRowSize, int boardColSize, int i, int j, char *word, int now) {
    if (word[now] == '\0') {
        ans = true;
        return;

    }

    if (i+1 < boardRowSize && !flag[i+1][j] && board[i+1][j] == word[now]) {
        flag[i+1][j] = true;
        dfs(flag, board, boardRowSize, boardColSize, i+1, j, word, now+1);
        flag[i+1][j] = false;

    }

    if (i-1 >= 0 && !flag[i-1][j] && board[i-1][j] == word[now]) {
        flag[i-1][j] = true;
        dfs(flag, board, boardRowSize, boardColSize, i-1, j, word, now+1);
        flag[i-1][j] = false;

    }

    if (j+1 < boardColSize && !flag[i][j+1] && board[i][j+1] == word[now]) {
        flag[i][j+1] = true;
        dfs(flag, board, boardRowSize, boardColSize, i, j+1, word, now+1);
        flag[i][j+1] = false;

    }

    if (j-1 >= 0 && !flag[i][j-1] && board[i][j-1] == word[now]) {
        flag[i][j-1] = true;
        dfs(flag, board, boardRowSize, boardColSize, i, j-1, word, now+1);
        flag[i][j-1] = false;

    }
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    bool **flag = (bool **)malloc(sizeof(bool *) * boardRowSize) ;
    int i, j;

    for (i = 0; i < boardRowSize; ++i) {
        flag[i] = (bool *)malloc(sizeof(bool) * boardColSize);
        for (j = 0; j < boardColSize; ++j) {
            flag[i][j] = false;
        }

    }

    if (strlen(word) == 0) return false;
    for (i = 0; i < boardRowSize; ++i) {
        for (j = 0; j < boardColSize; ++j) {
            if (board[i][j] == word[0]) {
                flag[i][j] = true;
                dfs(flag, board, boardRowSize, boardColSize, i, j, word, 1);
                if (ans) return ans;
                flag[i][j] = false;

            }

        }

    }

    return ans;

}

int main()
{
    vector<string> test;
    test.push_back("ABCE");
    test.push_back("SFCS");
    test.push_back("ADEE");
    int boardColSize = 4, boardRowSize = 3;
    char **board = (char **)malloc(sizeof(char *) * boardRowSize) ;
    int i, j;

    for (i = 0; i < boardRowSize; ++i) {
        board[i] = (char *)malloc(sizeof(char) * boardColSize);
        for (j = 0; j < boardColSize; ++j) {
            board[i][j] = test[i][j];
        }
    }
    char word[10] = {'A', 'B', 'C', 'C', 'E', 'E', '\0'};
    cout << exist(board, 3, 4, word) << endl;
}
