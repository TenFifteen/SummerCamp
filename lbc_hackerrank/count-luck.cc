#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<string> &forest, int x, int y) {
    if (x < 0 || y < 0 || x >= forest.size() || y >= forest[0].size()) return -1;
    if (forest[x][y] == 'X') return -1;
    if (forest[x][y] == '*') return 0;
    //cout << "seaching " << x << " " << y << endl;
    
    const int ix[] = {-1, 0, 1, 0};
    const int iy[] = {0, -1, 0, 1};
    
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int xx = x + ix[i], yy = y + iy[i];
        // using forest[xx][yy] == '.' will fail because of '*' is also throughable.
        if (xx >= 0 && yy >= 0 && xx < forest.size() && yy < forest[0].size() && forest[xx][yy] != 'X') cnt++;
    }
    
    forest[x][y] = 'X';
    for (int i = 0; i < 4; ++i) {
        int xx = x + ix[i], yy = y + iy[i];
        int ret = dfs(forest, xx, yy);
        if (ret >= 0) return (cnt > 1 ? 1 : 0) + ret;
    }
    return -1;
}

pair<int, int> findM(const vector<string> &forest) {
    for (int i = 0; i < forest.size(); ++i) {
        for (int j = 0; j < forest[i].size(); ++j) {
            if (forest[i][j] == 'M') return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> m >> n;
        vector<string> forest(m);
        for (int i = 0; i < m; ++i) {
            cin >> forest[i];
        }
        int k;
        cin >> k;
        
        pair<int, int> start = findM(forest);
        int ans = dfs(forest, start.first, start.second);
        //cout << ans << endl;
        if (ans == k) cout << "Impressed" << endl;
        else cout << "Oops!" << endl;
    }
    return 0;
}
