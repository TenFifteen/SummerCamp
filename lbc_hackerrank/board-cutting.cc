#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long mod = 1000000000L+7;
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<long long> horizontal(m-1), vertical(n-1);
        for (int i = 0; i < m-1; ++i) {
            cin >> horizontal[i];
        }
        for (int i = 0; i < n-1; ++i) {
            cin >> vertical[i];
        }
        sort(horizontal.begin(), horizontal.end());
        sort(vertical.begin(), vertical.end());
        long long i = m-2, j = n-2, ans = 0;
        while (i >= 0 || j >= 0) {
            if (i < 0) ans += vertical[j--]*(m-i-1);
            else if (j < 0) ans += horizontal[i--]*(n-j-1);
            else if (vertical[j] > horizontal[i]) ans += vertical[j--]*(m-i-1);
            else ans += horizontal[i--]*(n-j-1);
        }
        cout << ans % mod << endl;
    }
    return 0;
}
