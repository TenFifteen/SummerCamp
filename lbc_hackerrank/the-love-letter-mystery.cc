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
        int left = 0, right = s.size()-1;
        int ans = 0;
        while (left < right) {
            ans += abs(s[left++] - s[right--]);
        }
        cout << ans << endl;
    }
    return 0;
}
