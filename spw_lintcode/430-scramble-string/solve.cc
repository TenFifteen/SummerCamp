#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isScramble(string& s1, string& s2) {
    // Write your code here
    int n = s1.size(), m = s2.size();
    if (m != n) return false;
    if (s1 == s2) return true;

    for (int i = 1; i < n; ++i) {
        string l1 = s1.substr(0, i);
        string r1 = s1.substr(i);

        string l3 = s2.substr(0, i);
        string r3 = s2.substr(i);

        string l2 = s2.substr(0, n-i);
        string r2 = s2.substr(n-i);

        if (isScramble(l1, r2) && isScramble(l2, r1)) return true;
        if (isScramble(l1, l3) && isScramble(r1, r3)) return true;
    }

    return false;
}
int main()
{
    string s1 = "rgeat";
    string s2 = "great";

    cout << isScramble(s1, s2) << endl;
}
