#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.size() % 2 == 1) cout << -1 << endl;
        else {
            vector<int> count(26, 0);
            for (int i = s.size()/2; i < s.size(); ++i) {
                count[s[i]-'a']++;
            }
            for (int i = 0; i < s.size()/2; ++i) {
                count[s[i]-'a']--;
            }
            int ans = 0;
            for (int i = 0; i < count.size(); ++i) {
                if (count[i] > 0) ans += count[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}
