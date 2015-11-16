/*
ID: libench1
PROG: ariprog
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");

    int n, m;
    fin >> n >> m;

    set<int> s;
    vector<bool> flag(m*m*2+1, false);
    for (int i = 0; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
            s.insert(i*i + j*j);
            flag[i*i + j*j] = true;
        }
    }

    //for (auto i : s) {
    //    cout << i << endl;
    //}

    vector<pair<int, int> > ans;
    int maxlen = 2*m*m;
    if (n != 1) {
        maxlen /= (n-1);
    }
    for (int len = 1; len <= maxlen; ++len) {
        for (auto i : s) {
            if (i + (n-1)*len > 2*m*m) break;
            bool isok = true;
            for (int j = 1; j < n; ++j) {
                if (flag[i + len*j] == false) {
                    isok = false;
                    break;
                }
            }

            if (isok) {
                 ans.push_back(make_pair(i, len));
            }
        }
    }

    for (auto i : ans) {
        fout << i.first << " " << i.second << endl;
    }
    if (ans.size() == 0) {
         fout << "NONE" << endl;
    }
    return 0;
}
