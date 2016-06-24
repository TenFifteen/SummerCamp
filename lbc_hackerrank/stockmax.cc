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
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vector<int> peak(arr);
        for (int i = n-2; i >= 0; --i) {
            peak[i] = max(peak[i+1], arr[i]);
        }
        
        long long ans = 0;
        for (int i = 0; i < n-1; ++i) {
            if (arr[i] < peak[i+1]) ans += peak[i+1] - arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}
