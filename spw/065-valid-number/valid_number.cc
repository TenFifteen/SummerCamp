#include <string>
#include <iostream>

using namespace std;

/**
 * Problem: valid if a given string is numberic
 * Solve: construct a longest(include all kinds of cases) string, then we
 *        check the given string assuming it is the  longest
 * Tips: see the comments below
 */
bool isNumber(string s)
{
    int i = 0;
    // skip the spaces
    while (i < s.size()) {
        if (s[i] == ' ' || s[i] == '\t') ++i;
        else break;
    }

    // skip the symbol
    if (s[i] == '-' || s[i] == '+') {
        ++i;
    }

    // deal with the decimal, .3 and 3. are all legal
    int dot = 0, num = 0;
    while (i < s.size() && (s[i] >= '0' && s[i] <= '9' || s[i] == '.')) {
        s[i] == '.' ? ++dot : ++num;
        ++i;
    }
    if (dot > 1 || num == 0) return false;


    // deal with the exponential part
    //  10e3.3 is illegal because of the dot
    if (i < s.size() && s[i] == 'e') {
        ++i;
        if (s[i] == '-' || s[i] == '+') {
            ++i;
        }
        num = 0;
        while (i < s.size() && (s[i] >= '0' && s[i] <= '9')) {
            ++num;
            ++i;
        }
        // 0e0 is also legal
        if (num == 0) return false;
    }


    // skip the spaces
    while (i < s.size()) {
        if (s[i] == ' ' || s[i] == '\t') ++i;
        else break;
    }
    return i == s.size();

}


int main()
{
    string num;
    while (cin >> num) {
        if (isNumber(num)) {
            cout << num << " is a number" << endl;
        } else {
            cout << num << " is not a number" << endl;
        }
    }

    return 0;
}

class Solution {
    public:
        bool isNumber(string s) {
            int i = 0, n = s.size();

            while (i < n && (s[i] == ' ' || s[i] == '\t'))
                ++i;

            if (i < n && (s[i] == '+' || s[i] == '-'))
                ++i;

            bool number = false, hasPoint = false;
            while (i < n && (s[i] >= '0' && s[i] <= '9' || s[i] == '.')) {
                if (s[i] == '.')
                    if (hasPoint) return false;
                    else hasPoint = true;
                else
                    number = true;
                ++i;
            }

            if (number && i < n && s[i] == 'e') {
                ++i;
                if (i < n && (s[i] == '+' || s[i] == '-'))
                    ++i;

                number = false;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    number = true;
                    ++i;
                }
            }

            if (!number) return false;

            while (i < n && (s[i] == ' ' || s[i] == '\t'))
                ++i;
            return i == n;
        }
};
