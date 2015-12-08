/*
ID: libench1
PROG: lamps
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

struct Node {
    vector<int> lamps;
    Node(vector<int> &v) {
        lamps = v;
    }

    bool operator< (const Node &n) const {
        for (int i = 0; i < lamps.size(); ++i) {
            if (lamps[i] < n.lamps[i]) {
                return true;
            } else if (lamps[i] > n.lamps[i]) {
                return false;
            }
        }

        return false;
    }
};

void search(vector<int> &lamps, int c, int cur, set<Node> &ans) {
    if (c % 2 == 0) {
        ans.insert(lamps);
    }
    if (c == 0 || cur >= 4) {
        return;
    }

    switch(cur) {
        case 0:
            for (int i = 0; i < lamps.size(); ++i) {
                lamps[i] = !lamps[i];
            }
            search(lamps, c-1, cur+1, ans);
            for (int i = 0; i < lamps.size(); ++i) {
                lamps[i] = !lamps[i];
            }
            break;
        case 1:
            for (int i = 0; i < lamps.size(); i+=2) {
                 lamps[i] = !lamps[i];
            }
            search(lamps, c-1, cur+1, ans);
            for (int i = 0; i < lamps.size(); i+=2) {
                 lamps[i] = !lamps[i];
            }
            break;
        case 2:
            for (int i = 1; i < lamps.size(); i+=2) {
                 lamps[i] = !lamps[i];
            }
            search(lamps, c-1, cur+1, ans);
            for (int i = 1; i < lamps.size(); i+=2) {
                 lamps[i] = !lamps[i];
            }
            break;
        case 3:
            for (int i = 0; i < lamps.size(); i+=3) {
                 lamps[i] = !lamps[i];
            }
            search(lamps, c-1, cur+1, ans);
            for (int i = 0; i < lamps.size(); i+=3) {
                 lamps[i] = !lamps[i];
            }
            break;
        default:
            break;
    }

    search(lamps, c, cur+1, ans);
}

bool check(vector<int> &state, vector<int> &lamps) {
    for (int i = 0;i < state.size(); ++i) {
        if (state[i] == -1 || state[i] == lamps[i]) {
            continue;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");

    int n, c;
    fin >> n >> c;
    vector<int> state(n, -1);
    int tmp;
    while (true) {
        fin >> tmp;
        if (tmp == -1) {
            break;
        }
        state[tmp-1] = 1;
    }
    while (true) {
        fin >> tmp;
        if (tmp == -1) {
            break;
        }
        state[tmp-1] = 0;
    }

    if (c > 4) {
        c = 4;
    }

    set<Node> ans;
    vector<int> lamps(n, 1);
    search(lamps, c, 0, ans);

    int cnt = 0;
    for (auto a : ans) {
        if (check(state, a.lamps)) {
            cnt++;
            for (auto i : a.lamps) {
                fout << i;
            }
            fout << endl;
        }
    }

    if (cnt == 0) {
         fout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
