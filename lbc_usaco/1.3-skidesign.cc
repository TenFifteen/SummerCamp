/*
ID: libench1
PROG: skidesign
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");

    int n;
    fin >> n;
    vector<int> hill(n);
    for (int i = 0; i < n; ++i) {
        fin >> hill[i];
    }

    int total = INT_MAX;

    for (int i = 7; i < 93; ++i) {
        int cur = 0;

        for (int j = 0; j < n; ++j) {
            if (hill[j] < i-8) {
                cur += (i-8-hill[j]) * (i-8-hill[j]);
            } else if (hill[j] > i+9) {
                cur += (hill[j]-i-9) * (hill[j]-i-9);
            }
        }

        if (cur < total) {
            total = cur;
        }
    }

    fout << total << endl;

    return 0;
}
