/*
感觉图论里面就floyd有点难度了。看了好一会别人的博客才理解了这个动归。
见：https://zh.wikipedia.org/wiki/Floyd-Warshall%E7%AE%97%E6%B3%95
https://www.zhihu.com/question/30955032
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(n, 1000000));
    for (int i = 0; i < m; ++i) {
        int a, b, v;
        cin >> a >> b >> v;
        mat[a-1][b-1] = v;
    }
    for (int i = 0; i < n; ++i) {
        mat[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int a, b;
        cin >> a >> b;
        if (mat[a-1][b-1] < 1000000) cout << mat[a-1][b-1] << endl;
        else cout << -1 << endl;
    }

    return 0;
}
