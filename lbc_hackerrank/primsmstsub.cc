#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> edges(n+1);
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
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = -1;
        for (int j = 1; j <= n; ++j) {
            if (visited[j] == false) {
                if (cur < 0 || dist[j] < dist[cur]) {
                    cur = j;
                }
            }
        }
        //cout << "processing " << cur << endl;
        ans += dist[cur];
        visited[cur] = true;
        
        for (int j = 0; j < edges[cur].size(); ++j) {
            int next = edges[cur][j].first, val = edges[cur][j].second;
            dist[next] = min(dist[next], val);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
