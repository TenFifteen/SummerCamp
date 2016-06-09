#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin >> s;
    
    vector<int> count(26, 0);
    for (auto ch : s) count[ch-'a']++;
    
    vector<int> need(26);
    for (int i = 0; i < 26; ++i) {
        need[i] = count[i]/2;
    }
    
    vector<int> now(26, 0);
    string ans;
    ans.push_back(s.back());
    count[s.back()-'a']--; // here easy to forget.
    now[s.back()-'a']++;
    for (int i = s.size()-2; i >= 0; --i) {
        int index = s[i] - 'a';
        if (now[index] < need[index]) {
            while (ans.size() > 0 && ans.back() > s[i] && count[ans.back()-'a']+now[ans.back()-'a'] > need[ans.back()-'a']) {
                now[ans.back()-'a']--;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            count[index]--;
            now[index]++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
