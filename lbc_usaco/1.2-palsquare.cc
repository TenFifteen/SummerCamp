/*
ID: libench1
PROG: palsquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string to_b(int b, int n) {
    string ans;
    while (n) {
        int m = n % b;

        if (m > 9) {
            ans.push_back(m - 10 + 'A');
        } else {
            ans.push_back('0' + m);
        }

        n /= b;
    }

    for (int i = 0; i < ans.size()/2; ++i) {
        swap(ans[i], ans[ans.size()-1-i]);
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

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int b;
    fin >> b;

    for (int i = 1; i <= 300; ++i) {
         string squre = to_b(b, i*i);
         if (isPalindrome(squre)) {
             fout << to_b(b, i) << " " << squre << endl;
         }
    }

    return 0;
}
