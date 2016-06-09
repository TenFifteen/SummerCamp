#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin >> s;
    vector<int> count(26, 0);
    for (auto ch : s) {
        count[ch-'a']++;
    }
    
    int odds = 0;
    for (auto c : count) {
        if (c % 2 == 1) odds++;
    }
    if (odds < 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
