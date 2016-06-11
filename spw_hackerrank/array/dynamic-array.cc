/**
 * Problem:
 * Solve: vector<vector<int>>
 * Tips: no
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> seqList(n, vector<int>());
    int lastAns = 0;
    while (q--) {
        int no, x, y;
        cin >> no >> x >> y;
        int pos = (x ^ lastAns) % n;
        if (no == 1) {
            seqList[pos].push_back(y);
        } else {
            int m = seqList[pos].size();
            if (m == 0) {
                lastAns = 0;
            } else {
                lastAns = seqList[pos][y % m];
            }
            cout << lastAns << endl;
        }
    }

    return 0;
}

