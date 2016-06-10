#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans, total;

int dfs(int root, vector<vector<int>> &edges, vector<bool> &visited, vector<int> &weight) {
    visited[root] = true;
    int subWeight = 0;
    for (int i = 0; i < edges[root].size(); ++i) {
        if (visited[edges[root][i]] == false) {
            int ret = dfs(edges[root][i], edges, visited, weight);
            subWeight += ret;
            ans = min(ans, abs(total-ret-ret)); 
        }
    }
    return subWeight + weight[root];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> weight(n+1);
    total = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
        total += weight[i];
    }
    
    vector<vector<int>> edges(n+1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    ans = total;
    vector<bool> visited(n+1, false);
    dfs(1, edges, visited, weight);
    cout << ans << endl;
    
    return 0;
}
