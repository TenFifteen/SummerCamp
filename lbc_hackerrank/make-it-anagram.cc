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
    vector<int> count(26, 0);
    for (auto ch : s1) count[ch-'a']++;
    for (auto ch : s2) count[ch-'a']--;
    int ans = 0;
    for (auto c : count) ans += abs(c);
    cout << ans << endl;
    return 0;
}
