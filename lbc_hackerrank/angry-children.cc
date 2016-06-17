#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        
        int ans = INT_MAX;
        int left = 0, right = k-1;
        while (right < n) {
            ans = min(ans, arr[right++] - arr[left++]);
        }
        cout << ans << endl;
    }
    return 0;
}
