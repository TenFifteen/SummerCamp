#include <iostream>
#include <string>

using namespace std;

/**
 * Problem: Given, s1, s2, s3, find whether s3 is formed by interleaving of s1 and s2.
 * Solve: Dynamic programming, the subproblem is prefix.
 * Tips: We need no the third dimension because for specified i and j, the substring of
 *        s3 is specified too.
 */
bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size(), t = s3.size();
    if (m + n != t) return false;

    bool dp[m+1][n+1] = {true};
    for (int i = 1; i <= m; ++i) dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    for (int j = 1; j <= n; ++j) dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // the index of s3 is i+j-1 other than i+j-2, because if the index come from 0, we then have
            // two zero in the total, then(i-1 + j-1 + 1) = i+j-1
            dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1] || dp[i][j-1] && s2[j-1] == s3[i+j-1];
        }
    }

    return dp[m][n];

}
int main()
{
    string s = "song";
    cout << s.substr(1) << endl;
    cout << s.substr(4) << "===" << endl;
    if (s.substr(4) == "") cout << "haha" << endl;

    bool dp[2][2] = {true};
    cout << dp[0][0] << endl;
    cout << dp[1][0] << endl;
    cout << dp[0][1] << endl;
    cout << dp[1][1] << endl;

    return 0;
}
