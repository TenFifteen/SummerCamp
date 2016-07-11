#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/**
 * Problem: Given two binary strings, return their sum (also a binary string).
 * Solve: copy from the discuss board.
 * Tips: the condition is ||
 */
string addBinary(string a, string b)
{
    string s = "";

    int c = 0;
    int i = a.size() -1, j = b.size() -1;
    while (i >= 0 || j >= 0 || c) {
        c += i >= 0 ? a[i--]-'0' : 0;
        c += j >= 0 ? b[j--]-'0' : 0;
        s = (char)(c % 2 + '0') + s;
        c /= 2;
    }
    return s;
}

int main()
{
    string a, b;
    while (cin >> a >> b) {
        string r = addBinary(a, b);
        cout << "The result of " << a << " and " << b << " is " << r << endl;
    }

    return 0;
}

class Solution {
    public:
        string addBinary(string a, string b) {
            int carry = 0;
            int i = a.size() - 1, j = b.size() - 1;

            string ans = "";
            while (i >= 0 || j >= 0 || carry) {
                if (i >= 0) {
                    carry += (a[i] - '0');
                    --i;
                }

                if (j >= 0) {
                    carry += (b[j] - '0');
                    --j;
                }

                ans = (char)(carry % 2 + '0') + ans;
                carry /= 2;
            }

            return ans;
        }
};
