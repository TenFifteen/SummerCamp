#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSorted(const string &s) {
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] > s[i-1]) return false;
    }
    return true;
}

void reverse(string &s, int left, int right) {
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

string& nextPermutation(string &s) {
    int index = s.size()-2;
    while (s[index] >= s[index+1]) index--;
    
    int bigger = index+1;
    while (bigger < s.size() && s[bigger] > s[index]) bigger++;
    bigger--;
    
    swap(s[index], s[bigger]);
    reverse(s, index+1, s.size()-1);
    return s;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        
        if (isSorted(s)) {
            cout << "no answer" << endl;
        } else {
            cout << nextPermutation(s) << endl;
        }
    }
    return 0;
}
