/*
ID: libench1
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n;

    int cur = 2;
    vector<int> ans(7);
    for (int i = 1900; i < 1900+n; ++i) {
        for (int j = 0; j < 12; ++j) {
            ans[(cur+12)%7]++;
            if (j == 0 || j == 2 || j == 4 || j == 6 || j == 7 || j == 9 || j == 11) {
                cur += 31;
            } else if (j == 1) {
                if (i % 100 == 0) {
                    if (i % 400 == 0) {
                        cur += 29;
                    } else {
                        cur += 28;
                    }
                } else if (i % 4 == 0) {
                     cur += 29;
                } else {
                    cur += 28;
                }
            } else {
                cur += 30;
            }
            cur %= 7;
        }
    }

    fout << ans[0];
    for (int i = 1; i < 7; ++i) {
         fout << " " << ans[i];
    }
    fout << endl;
    return 0;
}
