#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        int index = n-1;
        while (index >= 0) {
            int left = index-1;
            while (left >= 0 && arr[index] - arr[left] <= 4) left--;
            ans ++;
            index = left;
        }
        cout << ans << endl;
    }
    return 0;
}
