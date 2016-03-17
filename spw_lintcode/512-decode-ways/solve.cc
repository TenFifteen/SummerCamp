#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem: A message containing letters from A-Z is being encoded
 *          to numbers using the following mapping:
 * Solve: dp
 * Tips: 1. When iterator, please write i instead of n;
 *       2. When we encounter an 0, then return 0;
 */
int numDecodings(string& s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;

    vector<int> dp(n+1, 1);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (s[i-1] != '0') dp[i] = dp[i-1];
        else dp[i] = 0;

        int code = (s[i-2] - '0') * 10 + (s[i-1] - '0');
        if (code <= 26 && code >= 10) {
            dp[i] += dp[i-2];
        }

        if (dp[i] == 0) return 0;

    }

    return dp[n];

}

int main()
{
    string s;
    while (cin >> s) {
        cout << numDecodings(s) << endl;
    }

    return 0;
}
