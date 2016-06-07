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
        int n, a, b;
        cin >> n >> a >> b;
        if (n < 2) {
            cout << 0 << endl;
        } else if (a == b) {
            cout << a*(n-1) << endl;
        } else {
            if (a > b) swap(a, b);
            int ans = (n-1) * a;
            cout << ans;
            for (int i = 0; i < n-1; ++i) {
                ans -= a;
                ans += b;
                cout << " " << ans;
            }
            cout << endl;
        }
    }
    return 0;
}
