#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        int index = n-1;
        int mul = 1;
        while (index >= 0) {
            for (int i = 0; i < k && index >= 0; ++i) {
                ans += arr[index--] * mul;
            }
            mul++;
        }
        cout << ans << endl;
    }
    return 0;
}
