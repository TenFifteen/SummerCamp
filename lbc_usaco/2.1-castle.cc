/*
ID: libench1
PROG: castle
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool noWall(int mask, int dir) {
    switch (dir) {
        case 0: return !(mask & 2);
        case 1: return !(mask & 4);
        case 2: return !(mask & 8);
        case 3: return !(mask & 1);
        default: return true;
    }
}

int search(int number, vector<vector<int> >&room, int x, int y, vector<vector<int> > &ans) {
    const int ix[] = {-1, 0, 1, 0};
    const int iy[] = {0, 1, 0, -1};

    ans[x][y] = number;

    int ret = 1;

    for (int i = 0; i < 4; ++i) {
        int xx = x + ix[i];
        int yy = y + iy[i];

        if (noWall(room[x][y], i) && ans[xx][yy] == 0) {
            ret += search(number, room, xx, yy, ans);
        }
    }

    return ret;
}

int solve(unordered_map<int, int> &um, vector<vector<int> > &room, vector<vector<int> > &ans) {
    int cnt = 0;
    int ret = 0;
    int n = room.size(), m = room[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans[i][j] == 0) {
                int r = search(++cnt, room, i, j, ans);
                um[cnt] = r;
                if (r > ret) {
                    ret = r;
                }
            }
        }
    }

    return ret;
}

pair<int, char> remove(unordered_map<int, int> &um, vector<vector<int> > &room, vector<vector<int> > &ans, int x, int y) {
    pair<int, char> ret = make_pair(-1, 'E');
    if (x != 0 && !noWall(room[x][y], 0) && ans[x][y] != ans[x-1][y]) {
         ret.first = um[ans[x][y]] + um[ans[x-1][y]];
         ret.second = 'N';
    }
    if (y+1 < room[0].size() && !noWall(room[x][y], 1) && ans[x][y] != ans[x][y+1]) {
        int cur = um[ans[x][y]] + um[ans[x][y+1]];
        if (cur > ret.first) {
            ret.first = cur;
            ret.second = 'E';
        }
    }

    return ret;
}

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");

    int n, m;
    fin >> m >> n;
    vector<vector<int> > room(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fin >> room[i][j];
        }
    }

    vector<vector<int> > ans(n, vector<int>(m, 0));
    unordered_map<int, int> um;

    int big = solve(um, room, ans);

    fout << um.size() << endl;
    fout << big << endl;

    int total = -1;
    int x , y;
    char dir ;
    for (int i = 0; i < m; ++i) {
        for (int j = n-1; j >= 0; --j) {
            auto ret = remove(um, room, ans, j, i);
            if (ret.first > total) {
                 total = ret.first;
                 x = j;
                 y = i;
                 dir = ret.second;
            }
        }
    }

    fout << total << endl;
    fout << x+1 << " " << y+1 << " " << dir << endl;

    return 0;
}
