#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long mod = 1000000007L;

int main() {
    string s;
    cin >> s;
    
    long long cur = s[0]-'0', last = 0;
    for (int i = 1; i < s.size(); ++i) {
        last += cur;
        cur *= 10;
        cur += (i+1)*(s[i]-'0');
        cur %= mod;
    }
    cout << (last+cur)%mod << endl;
    return 0;
}
