#include <iostream>
#include <vector>
using namespace std;

#define MAXM 100002
#define MAXN 512

int need[MAXN], value[MAXN];
int dp[MAXM];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> need[i] >> value[i];
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 1; i <= m; ++i) {
            if (i >= need[k]) {
                dp[i] = max(dp[i], dp[i-need[k]] + value[k]);
            }
        }
    }

    cout << dp[m] << endl;
    return 0;
}
