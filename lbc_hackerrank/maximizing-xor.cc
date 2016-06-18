#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int L, R;
    while (cin >> L >> R) {
        int ans = -1;
        for (int i = L; i <= R; ++i) {
            for (int j = i+1; j <= R; ++j) {
                ans = max(ans, i^j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
