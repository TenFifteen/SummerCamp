/*
ID: libench1
PROG: maze1
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
#include <stack>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");

    FILE *in = fopen("maze1.in", "r");
    FILE *out = fopen("maze1.out", "r");

    int w, h;
    //fin >> w >> h;
    fscanf(in, "%d%d", &w, &h);
    fgetc(in);
    vector<vector<char> > maze(h*2+1, vector<char>(w*2+1));
    for (int i = 0; i < h*2+1; ++i) {
        for (int j = 0; j < w*2+1; ++j) {
            maze[i][j] = fgetc(in);
        }
        fgetc(in);
    }

    queue<pair<int, int> > cur;
    vector<vector<int> > dist(h, vector<int>(w, 0));

    for (int i = 1; i < h*2+1; i+=2) {
        if (maze[i][0] == ' ') {
             dist[i/2][0] = 1;
             cur.push(make_pair(i/2, 0));
        } else if (maze[i][w*2] == ' ') {
            dist[i/2][w-1] = 1;
            cur.push(make_pair(i/2, w-1));
        }
    }
    for (int i = 1; i < w*2+1; i+=2) {
        if (maze[0][i] == ' ') {
             dist[0][i/2] = 1;
             cur.push(make_pair(0, i/2));
        } else if (maze[h*2][i] == ' ') {
            dist[h-1][i/2] = 1;
            cur.push(make_pair(h-1, i/2));
        }
    }

    int ret = 1;
    while (cur.size() > 0) {
        pair<int, int> p = cur.front();
        cur.pop();

        int x = p.first;
        int y = p.second;

        static const int ix[] = {-1, 0, 1, 0};
        static const int iy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; ++i) {
            int nx = x+ix[i];
            int ny = y+iy[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (dist[nx][ny] != 0 || maze[x*2+1+ix[i]][y*2+1+iy[i]] != ' ') continue;

            dist[nx][ny] = dist[x][y]+1;
            if (dist[nx][ny] > ret) {
                ret = dist[nx][ny];
            }
            cur.push(make_pair(nx, ny));
        }
    }

    fout << ret << endl;

    return 0;
}
