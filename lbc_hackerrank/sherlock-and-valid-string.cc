/*
这道题目陷阱好深啊。
见下面的special case
*/
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
    for (auto ch : s) {
        count[ch-'a']++;
    }
    int least = s.size();
    for (int i = 0; i < 26; ++i) {
        if (count[i] != 0) least = min(least, count[i]);
    }
    
    int total = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > least) total += count[i] - least;
    }
    if (total < 2) cout << "YES" << endl;
    else {
        // special case. like aaabbbc
        if (least == 1) {
            int cnt = 0;
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (count[i] == least) {
                    cnt++;
                    count[i] = 0;
                }
            }
            if (cnt == 1) {
                int last = -1;
                for (int i = 0; i < 26; ++i) {
                    if (count[i] != 0) {
                        if (last < 0) last = count[i];
                        else if (last != count[i]) ok = false;
                    }
                }
            } else {
                ok = false;
            }
            if (ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
