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
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= k) {
                total++;
                k -= arr[i];
            }
            else break;
        }
        cout << total << endl;
    }
    return 0;
}
