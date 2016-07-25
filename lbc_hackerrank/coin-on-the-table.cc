#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = 0;
    for (int t = 0; t < k; ++t) {
        vector<vector<int>> next(dp);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                next[i][j] = dp[i][j];
                if (i > 0 && dp[i-1][j] != INT_MAX && grid[i-1][j] != '*') {
                    next[i][j] = min(next[i][j], grid[i-1][j] == 'D' ? dp[i-1][j] : dp[i-1][j] + 1);
                }
                if (j > 0 && dp[i][j-1] != INT_MAX && grid[i][j-1] != '*') {
                    next[i][j] = min(next[i][j], grid[i][j-1] == 'R' ? dp[i][j-1] : dp[i][j-1] + 1);
                }
                if (i < n-1 && dp[i+1][j] != INT_MAX && grid[i+1][j] != '*') {
                    next[i][j] = min(next[i][j], grid[i+1][j] == 'U' ? dp[i+1][j] : dp[i+1][j] + 1);
                }
                if (j < m-1 && dp[i][j+1] != INT_MAX && grid[i][j+1] != '*') {
                    next[i][j] = min(next[i][j], grid[i][j+1] == 'L' ? dp[i][j+1] : dp[i][j+1] + 1);
                }
            }
        }
        dp = next;
    }
    
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                ans = dp[i][j];
            } 
        }
    }
    
    if (ans != INT_MAX) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}
