/**
 * Problem: You are given a square map of size N*N. Each cell of the map
 *          has a value denoting its depth. We will call a cell of the
 *          map a cavity if and only if this cell is not on the border of
 *          the map and each cell adjacent to it has strictly smaller
 *          depth. Two cells are adjacent if they have a common side (edge).
 * Solve: judge and output in the same loop to avoid the aside buffer.
 * Tips: If we think further, we will find that the 'X' is big than '0'~'9'
 *       Then if we set in place, it will not affect the latter judgement.
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isCavity(vector<string> &grid, int x, int y) {
    int di[] = {1, 0, -1, 0};
    int dj[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
        if (grid[x][y] <= grid[x+di[i]][y+dj[i]]) {
            return false;
        }
    }

    return true;
}

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != 0 && i != n-1 && j != 0 && j != n-1
                    && isCavity(grid, i, j)) {
                cout << 'X';
                // we can just set here grid[i][j] = 'X'
            } else {
                cout << grid[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}

