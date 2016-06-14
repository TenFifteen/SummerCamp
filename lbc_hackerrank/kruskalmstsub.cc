#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, v;
    bool operator< (const Edge &e) const {
        if (v < e.v) return true;
        if (v > e.v) return false;
        return a+b+v < e.a+e.b+e.v;
    }
};

int Find(vector<int> &fa, int x) {
    if (x == fa[x]) return x;
    int ret = Find(fa, fa[x]);
    fa[x] = ret;
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].v;
    }
    int start;
    cin >> start; // useless
    
    sort(edges.begin(), edges.end());
    vector<int> fa(n+1);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < m && cnt < n-1; ++i) {
        int fa1 = Find(fa, edges[i].a);
        int fa2 = Find(fa, edges[i].b);
        if (fa1 != fa2) {
            ans += edges[i].v;
            cnt++;
            fa[fa1] = fa[fa2];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
