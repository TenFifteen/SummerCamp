#include <iostream>
using namespace std;

const int maxn = 128;
int matrix[maxn][maxn];
int dp[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[i] = matrix[n-1][i];
    }

    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[j] = max(dp[j], dp[j+1]) + matrix[i][j];
        }
    }

    cout << dp[0] << endl;
    return 0;
}
