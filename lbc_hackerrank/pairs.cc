#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    int last = 0, first = 1;
    int ans = 0;
    while (first < n) {
        if (arr[first] - arr[last] == k) {
            ans++;
            first++;
            last++;
        } else if (arr[first] - arr[last] < k) {
            first++;
        } else {
            last++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
