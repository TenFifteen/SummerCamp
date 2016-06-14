#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(n+1);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        int start;
        cin >> start;
        
        queue<int> q;
        q.push(start);
        vector<int> dist(n+1, -1);
        vector<bool> visited(n+1, false);
        visited[start] = true;
        int level = 6;
        while (q.size() > 0) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < edges[cur].size(); ++j) {
                    int next = edges[cur][j];
                    if (visited[next] == false) {
                        visited[next] = true;
                        dist[next] = level;
                        q.push(next);
                    }
                }
            }
            level += 6;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (i != start) cout << dist[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
