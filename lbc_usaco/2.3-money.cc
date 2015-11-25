/*
ID: libench1
PROG: money
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");

    int v, n;
    fin >> v >> n;
    vector<int> coins(v);
    for (int i = 0; i < v; ++i) {
        fin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    vector<vector<long long> > dp(n+1, vector<long long>(v+1, 0));
    for (int i = 0; i <= v; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= v; ++j) {
            if (i >= coins[j-1]) {
                dp[i][j] = dp[i-coins[j-1]][j] + dp[i][j-1];
            } else {
                 dp[i][j] = dp[i][j-1];
            }
        }
    }

    fout << dp[n][v] << endl;

    return 0;
}
