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
        int n, c, m;
        cin >> n >> c >> m;
        int ans = n / c;
        int wrapper = ans;
        while (wrapper >= m) {
            int next =  wrapper / m;
            ans += next;
            wrapper %= m;
            wrapper += next;
        }
        cout << ans << endl;
    }
    return 0;
}
