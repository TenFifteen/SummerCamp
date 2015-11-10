/*
ID: libench1
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n, ans = 0;
    fin >> n;
    string neck;
    fin >> neck;
    for (int i = 0; i < n; ++i) {
        int j = i+1;
        if (j == n) {
            j = 0;
        }
        char ch = neck[i];
        while (j != 1 && (ch == 'w' || neck[j] == ch || neck[j] == 'w')) {
            if (ch == 'w' && neck[j] != 'w') {
                ch = neck[j];
            }
            j++;
            if (j == n) {
                j = 0;
            }
        }
        if (j == i) {
             ans = n;
             break;
        }
        int last = j;
        ch = neck[j];
        j++;
        if (j == n) {
             j = 0;
        }
        while (j != i && (ch == 'w' || neck[j] == 'w' || neck[j] == ch)) {
            if (ch == 'w' && neck[j] != 'w') {
                ch = neck[j];
            }
            j++;
            if (j == n) {
                j = 0;
            }
        }
        int cur = j - i;
        if (cur <= 0) {
             cur += n;
        }
        if (cur > ans) {
            ans = cur;
        }
    }
    if (ans == 0) {
        ans = n;
    }

    fout << ans << endl;
    return 0;
}
