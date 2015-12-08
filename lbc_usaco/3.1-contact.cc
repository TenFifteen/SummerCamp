/*
ID: libench1
PROG: contact
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
#include <cstring>

using namespace std;

struct Cmp {
    bool operator() (const string s1, const string s2) {
        if (s1.size() < s2.size()) return true;
        if (s1.size() > s2.size()) return false;
        return s1 < s2;
    }
};

int main() {
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");

    int a, b, n;
    fin >> a >> b >> n;

    string input, tmp;
    while (fin >> tmp) {
        input.append(tmp);
    }

    unordered_map<string, int> m;
    for (int i = a; i <= b; ++i) {
        for (int j = 0; j+i-1 < input.size(); ++j) {
            m[input.substr(j, i)]++;
        }
    }

    map<int, vector<string> > res;
    for (auto it : m) {
        res[it.second].push_back(it.first);
    }

    for (int i = 0; i < n; ++i) {
        if (res.size() == 0) break;
        int cur = res.rbegin()->first;
        vector<string> ans(res.rbegin()->second);
        res.erase(cur);

        sort(ans.begin(), ans.end(), Cmp());

        fout << cur << endl;
        int index = 0;
        while (index < ans.size()) {
             fout << ans[index++];
             for (int j = 0; j < 5 && index < ans.size(); ++j) {
                 fout << " " << ans[index++];
             }
             fout << endl;
        }
    }

    return 0;
}
