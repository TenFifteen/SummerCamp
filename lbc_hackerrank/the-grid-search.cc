#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1024;
int matrix[maxn][maxn], pattern[maxn][maxn];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C;
        for (int i = 0; i < R; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j < C; ++j) {
                matrix[i][j] = str[j];
            }
        }
        
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j < c; ++j) {
                pattern[i][j] = str[j];
            }
        }
        
        bool ok = false;
        for (int i = 0; i <= R-r && !ok; ++i) {
            for (int j = 0; j <= C-c && !ok; ++j) {
                bool found = true;
                for (int ii = 0; ii < r && found; ++ii) {
                    for (int jj = 0; jj < c && found; ++jj) {
                        if (matrix[ii+i][jj+j] != pattern[ii][jj]) found = false;
                    }
                }
                ok = found;
            }
        }
        
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
