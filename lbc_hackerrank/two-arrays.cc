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
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (A[i] + B[n-1-i] < k) {
                ok = false;
                break;
            } 
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
