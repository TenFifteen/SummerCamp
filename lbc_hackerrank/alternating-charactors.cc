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
        int total = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) total++;
        }
        cout << total << endl;
    }
    return 0;
}
