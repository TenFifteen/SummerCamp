/*
ID: libench1
PROG: cowtour
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
#include <iomanip>

using namespace std;

unordered_set<int> findField(int p, vector<vector<bool> > &edge, vector<bool> &flag) {
    unordered_set<int> ret;

    queue<int> q;
    q.push(p);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (ret.find(cur) != ret.end()) {
            continue;
        }

        ret.insert(cur);
        flag[cur] = true;

        for (int i = 0; i < edge[cur].size(); ++i) {
            if (edge[cur][i] == true && ret.find(i) == ret.end()) {
                q.push(i);
            }
        }
    }

    return ret;
}

double getDistance(pair<int, int> a, pair<int, int> b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

void shortestPath(unordered_set<int> &field, vector<vector<bool> > &edge, vector<pair<int, int> > &pasture, vector<double> &dist) {
    vector<int> p;
    for (auto i : field) {
        p.push_back(i);
    }

    for (int i = 0; i < p.size(); ++i) {
        vector<double> tmpDist(p.size(), INT_MAX);
        vector<int> flag(p.size());

        tmpDist[i] = 0;
        flag[i] = 1;
        for (int j = 1; j < p.size(); ++j) {
            int cur = -1;
            for (int c = 0; c < p.size(); ++c) {
                if (flag[c] == 1) {
                    if (cur == -1) {
                        cur = c;
                    } else if (tmpDist[c] < tmpDist[cur]) {
                        cur = c;
                    }
                }
            }
            flag[cur] = 2;

            for (int k = 0; k < p.size(); ++k) {
                if (edge[p[cur]][p[k]] == true && flag[k] < 2 && getDistance(pasture[p[cur]], pasture[p[k]])+tmpDist[cur] < tmpDist[k]) {
                    tmpDist[k] = getDistance(pasture[p[cur]], pasture[p[k]]) + tmpDist[cur];
                    flag[k] = 1;
                }
            }
        }

        double d = -1;
        for (int j = 0; j < p.size(); ++j) {
            if (tmpDist[j] > d) {
                d = tmpDist[j];
            }
        }

        dist[p[i]] = d;
    }
}

double addEdgeLen(unordered_set<int> &a, unordered_set<int> &b, vector<pair<int, int> > &pasture, vector<double> &dist) {
    double ret = INT_MAX;

    for (auto i : a) {
        for (auto j : b) {
            if (getDistance(pasture[i], pasture[j]) + dist[i] + dist[j] < ret) {
                ret = getDistance(pasture[i], pasture[j]) + dist[i] + dist[j];
            }
        }
    }

    return ret;
}

int main() {
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");

    int n;
    fin >> n;

    vector<pair<int, int> > pasture(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        fin >> a >> b;
        pasture[i] = make_pair(a, b);
    }

    vector<vector<bool> > edge(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        string input;
        fin >> input;
        for (int j = 0; j < n; ++j) {
            if (input[j] == '1') {
                edge[i][j] = true;
            }
        }
    }

    vector<unordered_set<int> > field;
    vector<bool> flag(n, false);
    for (int i = 0; i < n; ++i) {
        if (flag[i] == false) {
            unordered_set<int> f = findField(i, edge, flag);
            field.push_back(f);
        }
    }

    vector<double> dist(n);
    for (int i = 0; i < field.size(); ++i) {
        shortestPath(field[i], edge, pasture, dist);
    }

    double ans = INT_MAX;
    for (int i = 0; i < field.size(); ++i) {
        for (int j = i+1; j < field.size(); ++j) {
            double ret = addEdgeLen(field[i], field[j], pasture, dist);
            if (ret < ans) {
                ans = ret;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] > ans) {
            ans = dist[i];
        }
    }

    fout << fixed << setprecision(6) <<  ans << endl;

    return 0;
}
