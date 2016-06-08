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
        int tmp = n, ans = 0;
        while (tmp) {
            int d = tmp % 10;
            tmp /= 10;
            if (d != 0 && n % d == 0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
