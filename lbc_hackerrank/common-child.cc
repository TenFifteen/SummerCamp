#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            dp[i][j] = max(dp[i][j-1], dp[i][j]);
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
