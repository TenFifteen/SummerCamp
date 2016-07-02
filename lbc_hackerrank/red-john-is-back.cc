#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 64;
long long dp[maxn];

const int maxp = 217287;
bool prime[maxp];
long long ans[maxp];

void init() {
    dp[0] = 1;
    for (int i = 1; i <= 40; ++i) {
        dp[i] = dp[i-1];
        if (i >= 4) dp[i] += dp[i-4];
    }
    
    fill(prime, prime+maxp, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < maxp; ++i) {
        if (prime[i] == false) continue;
        for (int j = i+i; j < maxp; j += i) {
            prime[j] = false;
        }
    }
    
    for (int i = 2; i < maxp; ++i) {
        ans[i] = ans[i-1];
        if (prime[i] == true) ans[i]++;
    }
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << ans[dp[n]] << endl;
    }
    return 0;
}
