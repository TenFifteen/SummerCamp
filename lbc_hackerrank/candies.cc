#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<long long> ans(n, 1);
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i-1]) ans[i] = ans[i-1] + 1;
    }
    for (int i = n-2; i >= 0; --i) {
        if (arr[i] > arr[i+1]) ans[i] = max(ans[i], ans[i+1]+1);
    }
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += ans[i];
    }
    cout << total << endl;
    return 0;
}
