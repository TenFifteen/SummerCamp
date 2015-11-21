/*
ID: libench1
PROG: barn1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int m, s, c;
    fin >> m >> s >> c;
    vector<int> cows(c);
    for (int i = 0; i < c; ++i) {
        fin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    vector<int> intervals;
    for (int i = 1; i < cows.size(); ++i) {
        intervals.push_back(cows[i] - cows[i-1] - 1);
    }

    sort(intervals.begin(), intervals.end());

    int ans = cows[c-1] - cows[0] + 1;
    if (m >= c) {
        ans = c;
    }
    else for (int i = 0; i < m-1; ++i) {
        ans -= intervals[c-2-i];
    }

    fout << ans << endl;
    return 0;
}
