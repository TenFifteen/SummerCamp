/*
ID: libench1
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");

    int n;
    fin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        fin >> names[i];
    }
    unordered_map<string, int> money;
    unordered_map<string, vector<string> > friends;
    string cur;
    while (fin >> cur) {
         int total, num;
         fin >> total >> num;
         money[cur] = total;
         for (int i = 0; i < num; ++i) {
             string tmp;
             fin >> tmp;
             friends[cur].push_back(tmp);
         }
    }

    unordered_map<string, int> gifts;
    for (auto f : friends) {
         int g = money[f.first]/f.second.size();
         money[f.first] = g * f.second.size();
         for (auto o : f.second) {
             gifts[o] += g;
         }
    }

    for (int i = 0; i < n; ++i) {
        fout << names[i] << " " << gifts[names[i]] - money[names[i]] << endl;
    }

    return 0;
}
