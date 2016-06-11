/*
这是第一次写二分匹配的题目。
感觉上来讲，好像二分匹配应该是比较基础常见的算法了。
参考：http://www.cnblogs.com/pony1993/archive/2012/07/25/2607738.html
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 256;
bool grid[maxn][maxn];

void initGraph(const vector<pair<int,int>> &biker, const vector<pair<int,int>> &bike, long long limit) {
    for (int i = 0; i < biker.size(); ++i) {
        for (int j = 0; j < bike.size(); ++j) {
            long long dist = 0;
            long long diff = biker[i].first - bike[j].first;
            dist += diff * diff;
            diff = biker[i].second - bike[j].second;
            dist += diff * diff;
            if (dist <= limit) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
}

int link[maxn], vis[maxn];
bool bfs(int x, int m) {
    for (int i = 0; i < m; ++i) {
        if (grid[x][i] && !vis[i]) {
            vis[i] = 1;
            if (link[i] < 0 || bfs(link[i], m)) {
                link[i] = x;
                return true;
            }
            //vis[i] = 0;
        }
    }
    return false;
}

int maxFit(int n, int m) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int i = 0; i < maxn; ++i) {
            vis[i] = 0;
        }
        if (bfs(i, m)) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> biker(n);
    for (int i = 0; i < n; ++i) {
        cin >> biker[i].first >> biker[i].second;
    }
    vector<pair<int, int>> bike(m);
    for (int i = 0; i < m; ++i) {
        cin >> bike[i].first >> bike[i].second;
    }
    
    long long left = 0, right = 10000000000000000L;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        initGraph(biker, bike, mid);
        for (int i = 0; i < maxn; ++i) {
            link[i] = -1;
        }
        int ans = maxFit(n, m);
        //cout << "left " << left << " right " << right << " mid " << mid << " ans " << ans << endl;
        if (ans >= k) {
            right = mid;
        } else {
            left = mid+1;
        }
    }
    
    cout << left << endl;
    
    return 0;
}
