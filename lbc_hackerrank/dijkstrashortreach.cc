#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> edges(n+1);
        for (int i = 0; i < m; ++i) {
            int a, b, v;
            cin >> a >> b >> v;
            edges[a].push_back(make_pair(b, v));
            edges[b].push_back(make_pair(a, v));
        }
        int start;
        cin >> start;
        
        vector<int> dist(n+1, INT_MAX);
        dist[start] = 0;
        vector<bool> visited(n+1, false);
        for (int i = 0; i < n; ++i) {
            int cur = -1;
            for (int j = 1; j <= n; ++j) {
                if (visited[j] == false) {
                    if (cur < 0 || dist[cur] > dist[j]) {
                        cur = j;
                    }
                }
            }
            if (cur < -1 || dist[cur] == INT_MAX) break; // to ensure unreachable nodes not visited.
            visited[cur] = true;
            
            for (int j = 0; j < edges[cur].size(); ++j) {
                int next = edges[cur][j].first, val = edges[cur][j].second;
                dist[next] = min(dist[next], dist[cur]+val);
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            if (i != start) {
                if (dist[i] != INT_MAX) {
                    cout << dist[i] << " ";
                } else {
                    cout << -1 << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
