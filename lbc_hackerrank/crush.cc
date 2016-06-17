#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<pair<int,int>> arr(m*2);
        int a, b, k;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> k;
            arr[i*2] = make_pair(a, -k);
            arr[i*2+1] = make_pair(b, k);
        }
        
        sort(arr.begin(), arr.end());
        
        long long cur = 0, ans = 0;
        for (int i = 0; i < 2*m; ++i) {
            cur -= arr[i].second;
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
