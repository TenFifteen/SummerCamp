/*
ID: libench1
PROG: fact4
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
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");

    int n;
    fin >> n;

    vector<int> num(n);
    int five = 0;
    for (int i = 0; i < n; ++i) {
        num[i] = i+1;
        while (num[i] % 5 == 0) {
            five++;
            num[i] /= 5;
        }
    }

    for (int i = 0; i < n; ++i) {
        while ((num[i] & 0x1) == 0 && five != 0) {
            num[i] >>= 1;
            five--;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        ans *= num[i];
        ans %= 10;
    }

    fout << ans << endl;

    return 0;
}
