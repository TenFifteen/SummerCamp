#include <iostream>
using namespace std;

const int maxm = 100002;
int dp[maxm];

const int maxn = 512;
int need[maxn], value[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> need[i] >> value[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = m; j > 0; --j) {
            if (j >= need[i]) {
                dp[j] = max(dp[j], dp[j-need[i]]+value[i]);
            }
        }
    }

    cout << dp[m] << endl;
    return 0;
}
