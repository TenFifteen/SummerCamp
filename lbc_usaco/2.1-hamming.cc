/*
ID: libench1
PROG: hamming
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

int bitCount(int x) {
    int ret = 0;
    while (x) {
        if (x & 1) {
            ret++;
        }
        x >>= 1;
    }

    return ret;
}

bool hamming(int i, int j, int d) {
    return bitCount(i^j) < d;
}

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");

    int n, b, d;
    fin >> n >> b >> d;

    int total = (1 << b);
    vector<bool> ans(total, true);
    for (int i = 0; i < total; ++i) {
        if (ans[i]) {
            for (int j = i+1; j < total; ++j) {
                if (hamming(i, j, d)) {
                    ans[j] = false;
                }
            }
        }
    }

    vector<int> ret;
    for (int i = 0; i < total && n > 0; ++i) {
        if (ans[i] == true) {
            ret.push_back(i);
            n--;
        }
    }

    int cur = 0;
    while(cur < ret.size()) {
        fout << ret[cur++];
        for (int i = 0; i < 9 && cur < ret.size(); ++i) {
            fout << " " << ret[cur++];
        }
        fout << endl;
    }

    return 0;
}
