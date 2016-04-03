#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    int m = p.size(), n = s.size();

    vector<vector<bool> > dp(m, vector<bool>(n, false));

    dp[0][0] = true;
    for (int i = 1; i <= m; ++i) {
        if (p[i-1] == '*')
            dp[i][0] = dp[i-2][0];

    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[i-1] == '*') {
                // when p[0 ... i-1] match s[0 ... j-1] or s[1 ... j]
                bool case1 = (dp[i-1][j-1] || dp[i][j-1]) && (p[i-2] == '.' || p[i-2] == s[j-1]);
                // when p[1 ... i-1] or p[1 ... i-2] match s[1 ... j-1]
                dp[i][j] =  dp[i-1][j] || dp[i-2][j] || case1;
            } else if (p[i-1] == '.' || p[i-1] == s[j-1]) {
                dp[i][j] = dp[i-1][j-1];

            }

        }

    }

    return dp[m][n];

}

int main()
{
    string s = "aab";
    string p = "c*a*b";

    cout << isMatch(s, p) << endl;

    return 0;
}
