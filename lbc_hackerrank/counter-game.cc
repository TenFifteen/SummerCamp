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
        unsigned long long x;
        cin >> x;
        int cnt = 0;
        while (x != 1) {
            if ((x & (x-1)) == 0) {
                x >>= 1;
            } else {
                unsigned long long mask = 1L << 63;
                while ((mask & x) == 0) mask >>= 1;
                x -= mask;
            }
            cnt++;
        }
        if (cnt % 2) {
            cout << "Louise" << endl;
        } else {
            cout << "Richard" << endl;
        }
    }
    return 0;
}
