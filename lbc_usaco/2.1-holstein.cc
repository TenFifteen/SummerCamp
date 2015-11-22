/*
ID: libench1
PROG: holstein
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int ans = INT_MAX;
vector<int> seq;

bool isValid(vector<int> &req, vector<int> &now) {
    for (int i = 0; i < req.size(); ++i) {
        if (req[i] > now[i]) {
            return false;
        }
    }

    return true;
}

void add(vector<int> &now, vector<int> &a) {
    for (int i = 0; i < now.size(); ++i) {
        now[i] += a[i];
    }
}

void minu(vector<int> &now, vector<int> &a) {
    for (int i = 0; i < now.size(); ++i) {
        now[i] -= a[i];
    }
}

void search(vector<vector<int> > &vit, vector<int> &req, vector<int> &now, vector<int> flag, int cur) {
    if (cur >= vit.size() || flag.size() >= ans) {
        return;
    }

    flag.push_back(cur+1);
    add(now, vit[cur]);
    if (isValid(req, now)) {
        if (flag.size() < ans) {
            ans = flag.size();
            seq = flag;
        }
    } else {
        search(vit, req, now, flag, cur+1);
    }
    flag.pop_back();

    minu(now, vit[cur]);
    search(vit, req, now, flag, cur+1);
}

int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");

    int v;
    fin >> v;
    vector<int> req(v);
    for (int i = 0; i < v; ++i) {
        fin >> req[i];
    }

    int g;
    fin >> g;
    vector<vector<int> > vit(g, vector<int>(v));
    for (int i = 0; i < g; ++i) {
        for (int j = 0; j < v; ++j) {
            fin >> vit[i][j];
        }
    }

    vector<int> flag;
    vector<int> now(v);
    search(vit, req, now, flag, 0);

    fout << ans;
    for (int i = 0; i < seq.size(); ++i) {
        fout << " " << seq[i];
    }
    fout << endl;

    return 0;
}
