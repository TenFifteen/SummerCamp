/*
ID: libench1
PROG: humble
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
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");

    int k, n;
    fin >> k >> n;
    vector<int> prime(k);
    for (int i = 0; i < k; ++i) {
        fin >> prime[i];
    }

    set<int> ans;
    ans.insert(1);

    for (int i = 0; i < n; ++i) {
        int next = -1;
        for (int j = 0; j < k; ++j) {
             int small = (*ans.rbegin()+prime[j])/prime[j];
             auto it = ans.lower_bound(small);
             if (next < 0) {
                 next = (*it) * prime[j];
             } else {
                 next = min(next, (*it) * prime[j]);
             }
        }
        ans.insert(next);
    }

    fout << *ans.rbegin() << endl;

    return 0;
}
