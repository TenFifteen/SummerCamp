#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n ;++i) {
            cin >> arr[i];
        }
        
        vector<long long> sum(n);
        sum[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i-1] + arr[i];
        }
        
        if (n == 1 || sum[n-2] == 0 || sum[n-1]-sum[0] == 0) {
            cout << "YES" << endl;
        } else {
            bool ok = false;
            for (int i = 1; i < n-1; ++i) {
                if (sum[i-1] == sum[n-1]-sum[i]) {
                    ok = true;
                    break;
                }
            }
            if (ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
