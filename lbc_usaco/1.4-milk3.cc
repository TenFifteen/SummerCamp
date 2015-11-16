/*
ID: libench1
PROG: milk3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

struct State {
    int a, b, c;
    State(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }

    bool operator< (const State & s) const {
        if (a < s.a) return true;
        if (a > s.a) return false;
        if (b < s.b) return true;
        if (b > s.b) return false;
        return c < s.c;
    }
};

int A, B, C;

void search(State s, set<State> &flag) {
    if (flag.find(s) != flag.end()) {
        return ;
    }

    flag.insert(s);

    if (s.a != 0) {
         int p = min(B-s.b, s.a);
         search(State(s.a-p, s.b+p, s.c), flag);

         p = min(C-s.c, s.a);
         search(State(s.a-p, s.b, s.c+p), flag);
    }

    if (s.b != 0) {
        int p = min(A-s.a, s.b);
        search(State(s.a+p, s.b-p, s.c), flag);

        p = min(C-s.c, s.b);
        search(State(s.a, s.b-p, s.c+p), flag);
    }

    if (s.c != 0) {
         int p = min(A-s.a, s.c);
         search(State(s.a+p, s.b, s.c-p), flag);

         p = min(B-s.b, s.c);
         search(State(s.a, s.b+p, s.c-p), flag);
    }
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

    fin >> A >> B >> C;

    set<State> flag;

    search(State(0, 0, C), flag);

    set<int> ans;
    for (auto s : flag) {
        if (s.a != 0) continue;
         ans.insert(s.c);
    }

    vector<int> v;
    for (auto i : ans) {
        v.push_back(i);
    }
    fout << v[0];
    for (int i = 1; i < v.size(); ++i) {
         fout << " " << v[i];
    }
    fout << endl;

    return 0;
}
