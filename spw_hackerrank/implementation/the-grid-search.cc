/**
 * Problem: Given a 2D array of digits, try to find the occurrence of a
 *          given 2D pattern of digits. For example, consider the following 2D matrix:
 * Solve: just search.
 * Tips: if we use a sub-routine to do the search, there will be some cases timeout.
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> graph(R, vector<int>(C, 0));
        for(int i = 0; i < R; i++){
            string tmp;
            cin >> tmp;
            for (int j = 0; j < C; ++j)
                graph[i][j] = tmp[j] - '0';
        }

        int r, c;
        cin >> r >> c;
        vector<vector<int>> pattern(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            string tmp;
            cin >> tmp;
            for (int j = 0; j < c; ++j)
                pattern[i][j] = tmp[j] - '0';
        }

        bool find = false;
        int dr = R - r, dc = C - c;
        for (int i = 0; i <= dr; ++i) {
            for (int j = 0; j <= dc; ++j) {
                bool ok = true;
                // can't judge use a sub-routine
                for (int ii = 0; ii < r && ok; ++ii) {
                    for (int jj = 0; jj < c && ok; ++jj) {
                        if (graph[i+ii][j+jj] != pattern[ii][jj]) {
                            ok = false;
                        }
                    }
                }

                if (ok == true) {
                    find = true;
                    goto end;
                }
            }
        }

end:
        if (find) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}

