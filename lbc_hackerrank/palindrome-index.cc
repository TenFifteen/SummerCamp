#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(const string &s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = -1;
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-1-i]) {
                if (isPalindrome(s, i, s.size()-2-i)) ans = s.size()-1-i;
                else ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
