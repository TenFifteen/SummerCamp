#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    getline(cin, s);
    vector<bool> flag(26, false);
    for (auto ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            flag[ch-'a'] = true;
        } else if (ch >= 'A' && ch <= 'Z') {
            flag[ch-'A'] = true;
        }
    }
    bool ok = true;
    for (auto f : flag) {
        if (f == false) {
            ok = false;
            break;
        }
    }
    
    if (ok) cout << "pangram" << endl;
    else cout << "not pangram" << endl;
    return 0;
}
