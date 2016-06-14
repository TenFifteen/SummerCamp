/*
这道题一开始还是挺难想思路的。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> dfs(int root, const vector<vector<int>> &edges, vector<bool> &visited) {
    visited[root] = true;
    pair<int, int> ans = make_pair(0, 1);
    for (int i = 0; i < edges[root].size(); ++i) {
        int next = edges[root][i];
        if (visited[next] == true) continue;
        auto ret = dfs(next, edges, visited);
        ans.first += ret.first;
        if (ret.second % 2 == 1) ans.second++;
    }
    if (ans.second % 2 == 0) ans.first++;
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    vector<bool> visited(n, false);
    cout << dfs(0, edges, visited).first-1 << endl;

    return 0;
}
