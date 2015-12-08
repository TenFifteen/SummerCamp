/*
ID: libench1
PROG: subset
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

using namespace std;

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");

    int n;
    fin >> n;

    vector<int> data(n);
    for (int i = 0;i < n; ++i) {
        data[i] = i+1;
    }

    int total = n * (n+1) / 2;

    if (total & 1) {
         fout << 0 << endl;
         return 0;
    }

    total /= 2;
    vector<vector<long long> > dp(n+1, vector<long long>(total+1, 0));

    for (int i = 0; i <= n; ++i) {
         dp[i][0] = 1;
    }

    for (int j = 1; j <= total; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = dp[i-1][j];
            if (i <= j) {
                 dp[i][j] += dp[i-1][j-i];
            }
        }
    }

    fout << dp[n][total]/2 << endl;

    return 0;
}
