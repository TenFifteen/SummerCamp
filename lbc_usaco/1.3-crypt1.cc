/*
ID: libench1
PROG: crypt1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool is_valid(unordered_set<int> &us, int x) {
    while (x) {
        int cur = x % 10;
        x /= 10;
        if (us.find(cur) == us.end()) {
            return false;
        }
    }

    return true;
}

int count(unordered_set<int> &us) {
    int n = us.size();

    vector<int> v;
    for (auto i : us) {
        v.push_back(i);
    }

    int ans = 0;

    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int c = 0; c < n; ++c) {
                for (int d = 0; d < n; ++d) {
                    for (int e = 0; e < n; ++e) {
                        int x = v[a]*100 + v[b]*10 + v[c];
                        if (x * v[d] > 999) continue;
                        if (x * v[e] > 999) continue;
                        if (x * v[d] * 10 + x * v[e] > 9999) continue;
                        if (is_valid(us, x*v[d]) && is_valid(us, x*v[e]) && is_valid(us, x*v[d]*10+x*v[e])) {
                             ans++;
                             //cout << x << " * " << v[d] << v[e] << " = " << x * v[d] << " * 10 + " << x *v[e] << " = " << x*v[d]*10+x*v[e] << endl;;
                        }
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int n;
    fin >> n;
    unordered_set<int> us;
    for (int i = 0; i < n; ++i) {
        int tmp;
        fin >> tmp;
        us.insert(tmp);
    }

    fout << count(us) << endl;

    return 0;
}
