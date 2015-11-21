/*
ID: libench1
PROG: dualpal
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string to_base(int b, int n) {
    string ans;

    while (n) {
        int m = n % b;
        ans.push_back(m + '0');
        n /= b;
    }

    return ans;
}

bool isPalindrome(string s) {
    for (int i = 0; i < s.size()/2; ++i) {
        if (s[i] != s[s.size()-1-i]) {
            return false;
        }
    }

    return true;
}

bool isPalindrome(int n) {
    int cnt = 0;
    for (int b = 2; b <= 10; ++b) {
        if (isPalindrome(to_base(b, n))) {
            cnt++;
        }
        if (cnt > 1) return true;
    }

    return false;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int n, s;
    fin >> n >> s;

    s++;
    while (n > 0) {
        if (isPalindrome(s)) {
            fout << s << endl;
            n--;
        }
        s++;
    }

    return 0;
}
