#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> count(26, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector<bool> flag(26, false);
        for (auto ch : s) {
            if (flag[ch-'a'] == false) {
                flag[ch-'a'] = true;
                count[ch-'a']++;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] == n) ans++;
    }
    cout << ans << endl;
    return 0;
}
