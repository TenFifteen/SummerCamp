#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k, tmp;
        cin >> n >> k;
        int cnt = 0;
        while (n--) {
            cin >> tmp;
            if (tmp <= 0) ++cnt;
        }

        if (cnt >= k) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}

