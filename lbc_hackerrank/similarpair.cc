#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000004;
int bit[maxn];

void setBit(int val) {
    while (val < maxn) {
        bit[val]++;
        val += (val & -val);
    }
}

void unsetBit(int val) {
    while (val < maxn) {
        bit[val]--;
        val += (val & -val);
    }
}

long long getRange(int val) {
    long long ans = 0;
    while (val) {
        ans += bit[val];
        val -= (val & -val);
    }
    return ans;
}

long long dfs(int root, vector<vector<int>> &edges, int T) {
    int right = root+T, left = root-T-1;
    if (left < 0) left = 0;
    //cout << "visiting " << root << endl;
    //for (int i = 0; i < 6; ++i) cout << bit[i] << " ";
    //cout << endl;
    //cout << "right " << getRange(right) << " left " << getRange(left) << endl;
    long long ret = getRange(right) - getRange(left);
    
    setBit(root);
    for (int i = 0; i < edges[root].size(); ++i) {
        ret += dfs(edges[root][i], edges, T);
    }
    unsetBit(root);
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, T;
    cin >> n >> T;
    
    vector<vector<int>> edges(n+1);
    vector<int> degree(n+1, 0);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        degree[b]++;
    }
    
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 0) {
            root = i;
            break;
        }
    }
    
    cout << dfs(root, edges, T) << endl;
    
    return 0;
}
