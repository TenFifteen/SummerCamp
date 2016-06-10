#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>> &grid, int x, int y) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return 0;
    if (grid[x][y] == 0) return 0;
    
    int ans = 1;
    grid[x][y] = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            ans += dfs(grid, x+i, y+j);
        }
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(dfs(grid, i, j), ans);
        }
    }
    cout << ans << endl;
    
    return 0;
}
