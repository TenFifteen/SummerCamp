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
        int n, m;
        cin >> n >> m;
        if (m == 1) cout << 2 << endl;
        else cout << 2 - (n & 0x1) << endl;
    }
    return 0;
}
