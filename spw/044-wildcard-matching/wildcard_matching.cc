#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

bool getMatch(string s, string p, int m, int n, map<pair<int, int>, bool> &dp)
{
    int len1 = s.size();
    int len2 = p.size();

    if (m >= len1 || n >= len2) {
        return m >= len1 && n >= len2;
    }

    pair<int,int> key(m, n);
    if (dp.find(key) != dp.end()) return dp[key];

    int i = m, j = n;
    while (j < len2) {
        if (p[j] == '*') {
            if (getMatch(s, p, i, j+1, dp)) {
                return dp[key] = 1;
            }
        }

        if (i >= len1 || p[j] != '?' && p[j] != '*' && p[j] != s[i]) return dp[key] = 0;
        if (p[j] != '*') ++j;
        ++i;
    }

    return dp[key] = i >= len1 ? 1 : 0;
}



bool isMatch(string s, string p)
{
    int len1 = s.size();
    int len2 = p.size();
    map<pair<int, int>, bool>  dp;
    return getMatch(s, p, 0, 0, dp);
}

/**
 * Problem: Implement wildcard pattern matching with support
 *          for '?' and '*'.
 * Solve: dp
 * Tips: dp[0][0] = true;
 */
bool isMatch1(string s, string p)
{
    int len1 = s.size();
    int len2 = p.size();

    vector<bool> temp(len2+1, false);
    vector<vector<bool> > dp(len1+1, temp);
    dp[0][0] = true;
    for (int i = 1; i <= len2; ++i) {
        if (p[i-1] == '*') {
            dp[0][i] = true;
        } else {
            break;
        }
    }

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
            } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    return dp[len1][len2];
}

int main()
{
    string s, p;
    while (cin >> s >> p) {
        if (isMatch1(s, p)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

class Solution {
    public:
        bool isMatch(string s, string p) {
            int m = s.size(), n = p.size();

            vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
            dp[0][0] = true;

            for (int i = 1; i <= n && p[i-1] == '*'; ++i) dp[0][i] = dp[0][i-1];

            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (p[j-1] == '*') {
                        dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                    } else {
                        dp[i][j] = dp[i-1][j-1] && (p[j-1] == '?' || s[i-1] == p[j-1]);
                    }
                }
            }

            return dp[m][n];
        }
};
