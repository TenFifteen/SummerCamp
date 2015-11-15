/*
ID: libench1
PROG: wormhole
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    int n;
    fin >> n;
    unordered_map<int, unordered_set<int> > um;
    for (int i = 0; i < n; ++i) {
        int a, b;
        fin >> a >> b;
        um[b].insert(a);
    }

    int total = 0;
    for (auto m : um) {
        if (m.second.size() > 1) {
            total += m.second.size() * (m.second.size()-1) / 2;
        }
    }

    fout << total << endl;

    return 0;
}
