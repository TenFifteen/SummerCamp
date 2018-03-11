#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(vector<vector<char> > &board, int i, int j)
{
    queue<pair<int, int> > next;
    queue<pair<int, int> > now;

    queue<pair<int, int> > *next_ptr = &now;
    queue<pair<int, int> > *now_ptr = &next;

    now_ptr->push(make_pair(i, j));
    board[i][j] = 'B';

    int m = board.size();
    int n = board[0].size();
    while (!now_ptr->empty() || !next_ptr->empty()) {
        while (!now_ptr->empty()) {
            pair<int, int> it = now_ptr->front();
            now_ptr->pop();

            int x = it.first;
            int y = it.second;

            for (int s = 0; s < 4; ++s) {
                int a = x + dx[s];
                int b = y + dy[s];
                if (a < m && a >= 0 && b < n && b >= 0 && board[a][b] == 'O') {
                    next_ptr->push(make_pair(a, b));
                    board[a][b] = 'B';

                }

            }

        }

        queue<pair<int, int> > *tmp = now_ptr;
        now_ptr = next_ptr;
        next_ptr = tmp;

    }

}

/**
 * Problem: Given an 2D board containing 'X' and 'O', capture all regions surrounded by
 *          'X', A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * Solve: find the law, use BFS starting from 'O's on the boundary of the matrix and mark them
 *        as 'B', then flip all all 'O's to 'X' and 'B's to 'O'.
 * Tips: sigh~ so easy, but I haven't thought out it.
 */
void solve(vector<vector<char> >& board)
{
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
        if (board[i][0] == 'O'){
            bfs(board, i, 0);

        }
        if (board[i][n-1] == 'O'){
            bfs(board, i, n-1);

        }

        if (i == 0 || i == m-1) {
            for (int j = 1; j < n-1; ++j) {
                if (board[i][j] == 'O'){
                    bfs(board, i, j);

                }

            }

        }

    }


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'B') board[i][j] = 'O';
            else if (board[i][j] == 'O')  board[i][j] = 'X';

        }

    }


}
