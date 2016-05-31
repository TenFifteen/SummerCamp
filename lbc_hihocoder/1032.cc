#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;

        if (input == "") {
            cout << 0 << endl;
            continue;
        }

        string s(input.size()*2+1, '#');
        for (int i = 0; i < input.size(); ++i) s[i*2+1] = input[i];
        vector<int> dp(s.size(), 1);

        int id = 0, mx = 0;
        int ans = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (mx > i) {
                dp[i] = min(mx-i+1, dp[id*2-i]);
            }
            while (i-dp[i] >= 0 && i+dp[i] < s.size() && s[i-dp[i]] == s[i+dp[i]]) dp[i]++;

            if (dp[i]+i-1 > mx) {
                mx = dp[i]+i-1;
                id = i;
            }

            ans = max(ans, dp[i]-1);
        }

        //for (auto d : dp) cout << d << endl;

        cout << ans << endl;
    }

    return 0;
}
