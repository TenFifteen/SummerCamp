/*
ID: libench1
PROG: concom
LANG: C++11
*/

/*
这道题自己没有想出来，看了别人的解法还是半信半疑的试试的。
其实我现在还没有明确的想出来为什么可以这样子。
但是只能先接受了。
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

int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");

    int n;
    vector<vector<int> > share(101, vector<int>(101, 0));
    vector<vector<bool> > con(101, vector<bool>(101, false));
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, p;
        fin >> a >> b >> p;
        share[a][b] = p;
        if (p > 50) {
            con[a][b] = true;
        }
    }

    for (int i = 1; i <= 100; ++i) {
        con[i][i] = true;

        bool flag = true;
        while (flag) {
             flag = false;
             for (int j = 1; j <= 100; ++j) {
                 if (con[i][j] == false) {
                     int sum = 0;
                     for (int k = 1; k <= 100; ++k) {
                         if (con[i][k]) {
                             sum += share[k][j];
                         }
                         if (sum > 50) {
                            flag = true;
                            con[i][j] = true;
                            break;
                         }
                     }
                 }
                 if (flag) {
                     break;
                 }
             }
        }
    }

    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (i != j && con[i][j]) {
                fout << i << " " << j << endl;
            }
        }
    }

    return 0;
}
