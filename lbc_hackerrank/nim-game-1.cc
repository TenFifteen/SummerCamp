/*
这是经典的nim游戏的最初级的版本，但是我并不会。。。
不过这篇日志讲的非常好：http://www.physixfan.com/archives/547
*/
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
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n ; ++i) {
            int num;
            cin >> num;
            ans ^= num;
        }
        if (ans == 0) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    return 0;
}
