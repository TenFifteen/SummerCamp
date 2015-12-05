/*
ID: libench1
PROG: kimbits
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
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

long long dp[32][32];
long long buf[32][32];

int main() {
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");

    long long N, L, I;
    fin >> N >> L >> I;

    //vector<vector<long long> > dp(N+1, vector<long long>(L+1, 0));
    for (long long i = 0; i <= N; ++i) {
        dp[i][0] = 1;
    }
    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= i; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    //vector<vector<long long> > buf(N+1, vector<long long>(L+1, 0));
    for (long long i = 0; i <= N; ++i) {
        for (long long j = 0; j <= L; ++j) {
            long long sum = 0;
            for (long long k = 0; k <= j; ++k) {
                sum += dp[i][k];
            }
            buf[i][j] = sum;
        }
    }

    for (long long i = N; i > 0; --i) {
        if (I > buf[i-1][L]) {
            fout << "1";
            I -= buf[i-1][L];
            L--;
        } else {
            fout << "0";
        }
    }
    fout << endl;

    return 0;
}
