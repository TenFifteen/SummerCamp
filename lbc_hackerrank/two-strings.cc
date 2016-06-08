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
        string s1, s2;
        cin >> s1 >> s2;
        vector<bool> visited(26, false);
        for (auto ch : s1) {
            visited[ch-'a'] = true;
        }
        bool ok = false;
        for (auto ch : s2) {
            if (visited[ch-'a'] == true) {
                ok = true;
                break;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
