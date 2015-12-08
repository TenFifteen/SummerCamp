/*
ID: libench1
PROG: ttwo
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

using namespace std;

int xf, xc, yf, yc, df = 0, dc = 0;
vector<vector<char> > board(10, vector<char>(10));
unordered_set<int> us;
bool met = false;
bool possible = true;

static const int ix[] = {-1, 0, 1, 0};
static const int iy[] = {0, 1, 0, -1};

void oneStep() {
    if (xf == xc && yf == yc) {
        met = true;
        return;
    }

    int xfn = xf + ix[df];
    int yfn = yf + iy[df];
    if (xfn < 0 || xfn > 9 || yfn < 0 || yfn > 9 || board[xfn][yfn] == '*') {
        df += 1;
        df %= 4;
    } else {
         xf = xfn;
         yf = yfn;
    }

    int xcn = xc + ix[dc];
    int ycn = yc + iy[dc];
    if (xcn < 0 || xcn > 9 || ycn < 0 || ycn > 9 || board[xcn][ycn] == '*') {
        dc += 1;
        dc %= 4;
    } else {
         xc = xcn;
         yc = ycn;
    }

    int state = xf * 100000 + yf * 10000 + df * 1000 + xc * 100 + yc * 10 + dc;
    if (us.find(state) != us.end()) {
        possible = false;
        return;
    } else {
         us.insert(state);
    }
}

int main() {
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");

    for (int i = 0;i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            fin >> board[i][j];
            if (board[i][j] == 'F') {
                 xf = i;
                 yf = j;
            } else if (board[i][j] == 'C') {
                xc = i;
                yc = j;
            }
        }
    }

    int count = -1;
    while (possible & !met) {
        oneStep();
        count++;
    }

    if (met) {
        fout << count << endl;
    } else {
        fout << 0 << endl;
    }

    return 0;
}
