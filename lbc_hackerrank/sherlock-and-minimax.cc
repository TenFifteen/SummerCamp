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
        int p, q;
        cin >> p >> q;
        if (q <= arr[0]) cout << p << endl;
        else if (p >= arr[n-1]) cout << q << endl;
        else {
            int ans = -1, index;
            for (int i = 0; i < n-1; ++i) {
                int mid = (arr[i+1] + arr[i]) / 2;
                if (mid > q || mid < p) continue;
                
                if (mid - arr[i] > ans) {
                    ans = mid - arr[i];
                    index = mid;
                }
            }
            
            if (p <= arr[0]) {
                if (arr[0] - p >= ans) {
                    ans = arr[0] - p;
                    index = p;
                }
            } else {
                int i = 0;
                while (arr[i] < p) i++;
                int cur = min(arr[i] - p, p - arr[i-1]);
                if (cur >= ans) {
                    ans = cur;
                    index = p;
                }
            }
            
            if (q >= arr[n-1]) {
                if (q - arr[n-1] > ans) {
                    ans = q - arr[n-1];
                    index = q;
                }
            } else {
                int i = n-1;
                while (arr[i] > q) i--;
                int cur = min(q-arr[i], arr[i+1]-q);
                if (cur > ans) {
                    ans = cur;
                    index = q;
                }
            }
            
            cout << index << endl;
        } 
    }
    return 0;
}
