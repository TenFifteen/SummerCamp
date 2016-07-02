#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

/**
 * Problem: shudu
 * Solve: three flag vector
 * Tips: 1. every row and column we have 9 digits: 1...9
 *
 */
bool isValidSudoku(vector<vector<char> >& board)
{
    bool row[10][10];
    bool col[10][10];
    bool lattice[10][10];

    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(lattice, false, sizeof(lattice));

    // i < 9 not 10 because we have 9 digits
    // but the range is 1...9
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char now = board[i][j];
            if (now == '.') continue;
            int digit = now - '0';

            int lp = (i / 3) * 3 + j / 3;
            if (row[i][digit] || col[j][digit] || lattice[lp][digit])  return false;

            row[i][digit] = true;
            col[j][digit] = true;
            lattice[lp][digit] = true;
        }
    }

    return true;
}
int main()
{
    int n;
    while (~scanf("%d", &n)) {
        vector<vector<char> > board;
        for (int i = 0; i < 9; ++i) {
            vector<char> row;
            for (int j = 0; j < 9; ++j) {
                int now;
                scanf("%c", &now);
                row.push_back(now);
            }
            board.push_back(row);
        }
    }
}
/**
 the character begins with 1!!
*/
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            bool row[9][9] = {false};
            bool col[9][9] = {false};
            bool gird[9][9] = {false};

            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    row[i][j] = col[i][j] = gird[i][j] = false;
                }
            }
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    char num = board[i][j];
                    if (num == '.') continue;

                    int pos = (i / 3) * 3 + j / 3;
                    int k = num - '1';
                    if (row[i][k] || col[j][k] || gird[pos][k])
                        return false;

                    row[i][k] = col[j][k] = gird[pos][k] = true;
                }
            }

            return true;
        }
};
