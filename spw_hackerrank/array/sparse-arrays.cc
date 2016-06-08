/**
 * Problem: save and query.
 * Solve: hash map
 * Tips: no
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unordered_map<string, int> cnt;
    int n, q;
    cin >> n;
    while (n--) {
        string tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    cin >> q;
    while (q--) {
        string tmp;
        cin >> tmp;
        cout << cnt[tmp] << endl;
    }

    return 0;
}

