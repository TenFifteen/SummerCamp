#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int grid[16][16]; // 0 not decided, 1 first lose, 2 first win

void init() {
    grid[1][1] = 2;
    grid[1][2] = 2;
    grid[2][1] = 2;
    grid[2][2] = 2;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 2));
    q.push(make_pair(1, 1));
    q.push(make_pair(2, 1));
    q.push(make_pair(2, 2));
    
    const int ix[] = {-1, 1, -2, -2};
    const int iy[] = {-2, -2, 1, -1};
    
    while (q.size() > 0) {
        while (q.size() > 0) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = cur.first - ix[i];
                int y = cur.second - iy[i];
                if (x < 1 || y < 1 || x > 15 || y > 15) continue;
                if (grid[x][y] == 0) grid[x][y] = 1;
            }
        }
        
        for (int i = 1; i <= 15; ++i) {
            for (int j = 1; j <= 15; ++j) {
                if (grid[i][j] != 0) continue;
                bool ok = false;
                for (int k = 0; k < 4; ++k) {
                    int x = ix[k] + i;
                    int y = iy[k] + j;
                    if (x < 1 || x > 15 || y < 1 || y > 15) continue;
                    if (grid[x][y] != 1) {
                        ok = true;
                        break;
                    }
                }
                if (ok == false) {
                    grid[i][j] = 2;
                    q.push(make_pair(i, j));
                }
            }
        }
    }
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (grid[x][y] == 1) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}
