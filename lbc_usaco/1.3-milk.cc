/*
ID: libench1
PROG: milk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> milk(m);
    for (int i = 0; i < m; ++i) {
        fin >> milk[i].first >> milk[i].second;
    }

    sort(milk.begin(), milk.end());

    int total = 0;
    for (int i = 0; i < m; ++i) {
        if (n == 0) break;
        if (milk[i].second > n) {
            total += n * milk[i].first;
            break;
        } else {
            n -= milk[i].second;
            total += milk[i].first * milk[i].second;
        }
    }

    fout << total << endl;

    return 0;
}
