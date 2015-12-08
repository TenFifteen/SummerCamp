/*
ID: libench1
PROG: agrinet
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

int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");

    int n;
    fin >> n;
    int len;
    vector<vector<int> > edges(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> edges[i][j];
        }
    }

    vector<bool> flag(n, false);
    flag[0] = true;
    vector<int> dist(n, INT_MAX);
    for (int i = 1; i < n; ++i) {
        dist[i] = edges[0][i];
    }

    int total = 0;

    for (int i = 1; i < n; ++i) {
        int cur = -1;
        for (int j = 0; j < n; ++j) {
            if (flag[j] == false && dist[j] != INT_MAX) {
                if (cur == -1) {
                    cur = j;
                } else if (dist[j] < dist[cur]) {
                    cur = j;
                }
            }
        }

        total += dist[cur];

        flag[cur] = true;
        for (int j = 0; j < n; ++j) {
             dist[j] = min(dist[j], edges[cur][j]);
        }
    }

    fout << total << endl;

    return 0;
}
