#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        vector<int> dp(k+1);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (j >= arr[i]) dp[j] = max(dp[j], dp[j-arr[i]] + arr[i]);
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}
