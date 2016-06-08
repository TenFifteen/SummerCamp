/*
这道题目真是想了好一会，而且写起来也挺麻烦的。
不过幸好还是过了。
一开始还把题意看成了从任意一点出发都可以了。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

pair<unordered_set<int>, bool>
dfs(int fa, int now, unordered_map<int, vector<int>> &edges, unordered_map<int, int> &order) {
    unordered_set<int> ret;
    for (auto neighbor : edges[now]) {
        if (neighbor == fa) continue;
        auto sub = dfs(now, neighbor, edges, order);
        if (sub.second == false) return sub;
        for (auto x : sub.first) ret.insert(x);
    }

    vector<int> number;
    for (auto x : ret) number.push_back(order[x]);
    sort(number.begin(), number.end());

    bool isOrdered = true;
    if (number.size() != 0 && order.find(now) != order.end() && order[now]+1 != number[0]) {
        isOrdered = false;
    }

    for (int i = 1; i < number.size() && isOrdered == true; ++i) {
        if (number[i] != number[i-1]+1) {
            isOrdered = false;
        }
    }

    if (order.find(now) != order.end()) ret.insert(now);
    return make_pair(ret, isOrdered);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        unordered_map<int, vector<int>> edges;
        for (int i = 1; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int m;
        cin >> m;
        unordered_map<int, int> order;
        for (int i = 0; i < m; ++i) {
            int cur;
            cin >> cur;
            order[cur] = i;
        }

        auto ret = dfs(-1, 1, edges, order);  

        if (ret.second) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
