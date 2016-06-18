#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            ans ^= num;
        }
        cout << ans << endl;
    }
    return 0;
}

