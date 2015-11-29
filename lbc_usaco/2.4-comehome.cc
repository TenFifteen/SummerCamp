/*
ID: libench1
PROG: comehome
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

using namespace std;

int main() {
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");

    int p;
    vector<vector<int> > path(52, vector<int>(52, INT_MAX));
    fin >> p;
    for (int i = 0; i < p; ++i) {
        char a, b;
        int len, ai, bi;
        fin >> a >> b >> len;
        if (a >= 'a') {
            ai = a - 'a';
        } else {
            ai = a - 'A' + 26;
        }
        if (b >= 'a') {
            bi = b - 'a';
        } else {
            bi = b - 'A' + 26;
        }

        path[ai][bi] = min(path[ai][bi], len);
        path[bi][ai] = path[ai][bi];
    }

    vector<int> dist(52, INT_MAX);
    vector<int> flag(52, 0);
    dist[51] = 0;
    flag[51] = 1;
    int cur = 51;
    while (cur < 26 || cur == 51) {
        for (int i = 0;i < 52; ++i) {
            if (i != cur && flag[i] != 2 && path[cur][i] != INT_MAX) {
                dist[i] = min(dist[i], dist[cur] + path[cur][i]);
                flag[i] = 1;
            }
        }

        flag[cur] = 2;
        int next = -1;
        for (int i = 0; i < 52; ++i) {
            if (flag[i] == 1) {
                if (next < 0) {
                    next = i;
                } else if (dist[i] < dist[next]) {
                    next = i;
                }
            }
        }

        cur = next;
    }

    fout << (char)('A' + cur - 26) << " " << dist[cur] << endl;

    return 0;
}
