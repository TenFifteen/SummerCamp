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
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<long long> sum(n+1);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = n-1; i >= 0; --i) {
            sum[i] = sum[i+1] + arr[i];
        }
        
        vector<long long> dp(n);
        for (int i = n-1; i >= max(n-3, 0); --i) {
            dp[i] = sum[i];
        }
        for (int i = n-4; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                dp[i] = max(dp[i], sum[i]-dp[i+j+1]);
            }
        }
        cout << dp[0] << endl;
    }
    return 0;
}
