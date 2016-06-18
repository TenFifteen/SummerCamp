#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if ((i+1) * (n-i) % 2) {
                ans ^= num;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
