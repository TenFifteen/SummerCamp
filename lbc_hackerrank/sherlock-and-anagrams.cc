#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        unordered_map<string, int> um;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                string now = s.substr(i, j-i+1);
                sort(now.begin(), now.end());
                um[now]++;
            }
        }
        int ans = 0;
        for (auto u : um) {
            ans += u.second * (u.second-1);
        }
        cout << ans/2 << endl;
    }
    return 0;
}
