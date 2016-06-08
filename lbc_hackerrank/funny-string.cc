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
        
        vector<int> diff(s.size()-1);
        for (int i = 0; i < diff.size(); ++i) {
            diff[i] = abs(s[i+1]-s[i]);
        }
        
        bool funny = true;
        int left = 0, right = diff.size()-1;
        while (left < right) {
            if (diff[left++] != diff[right--]) funny = false;
        }
        
        if (funny) cout << "Funny" << endl;
        else cout << "Not Funny" << endl;
    }
    return 0;
}
