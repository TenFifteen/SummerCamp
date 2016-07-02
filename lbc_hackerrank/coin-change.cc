#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coin(m);
    for (int i = 0; i < m; ++i) {
        cin >> coin[i];
    }
    
    vector<vector<long long>> dp(m+1, vector<long long>(n+1));
    for (int i = 0; i <= m; ++i) dp[i][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k*coin[i-1] <= j; k++) {
                dp[i][j] += dp[i-1][j-k*coin[i-1]];
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}
