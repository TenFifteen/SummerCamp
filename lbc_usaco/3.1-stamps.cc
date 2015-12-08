/*
ID: libench1
PROG: stamps
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

struct state {
    int k, n, total;
    bool operator< (const state s) const {
        if (total < s.total) return true;
        if (total > s.total) return false;
        if (n < s.n) return true;
        if (n > s.n) return false;
        return k < s.k;
    }

    state(int kk, int nn ,int tt) {
        k = kk;
        n = nn;
        total = tt;
    }
};

int main() {
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");

    int n, k;
    fin >> k >> n;
    vector<int> stamp(n);
    for (int i = 0; i < n; ++i) {
        fin >> stamp[i];
    }

    sort(stamp.begin(), stamp.end());

    vector<int> dp(2000001);
    if (stamp[0] != 1) {
        fout << 0 << endl;
        return 0;
    }

    dp[1] = 1;
    for (int i = 2; i < 2000002 ; ++i) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (stamp[j] > i) break;
            if (stamp[j] == i) {
                dp[i] = 1;
                break;
            } else {
                dp[i] = min(dp[i], dp[i-stamp[j]] + 1);
            }
        }

        if (dp[i] > k) {
            fout << i-1 << endl;
            return 0;
        }
    }

    /*
    unordered_set<int> us;
    for (int i = 0; i < n; ++i) {
        us.insert(stamp[i]);
    }
    for (int i = 1; i < k; ++i) {
        unordered_set<int> next;
        for (int j = 0; j < n; ++j) {
            for (auto u : us) {
                next.insert(u + stamp[j]);
            }
        }
        for (auto u : next) {
            us.insert(u);
        }
    }

    for (int i = 1; ; ++i) {
        if (us.find(i) == us.end()) {
            fout << i-1 << endl;
            break;
        }
    }
    */

    return 0;
}
