#include <iostream>
using namespace std;


/**
 * Problem: Given an integer, convert it to a roman numeral.
 *          The number is guaranteed to be within the range from 1 to 3999.
 * Solve: make a table and iterator
 * Tips: see comments below
 */
string getBit(int d, int base) {
    static string table[4] = {
        "IIIVIIIX",
        "XXXLXXXC",
        "CCCDCCCM",
        // if we miss a comma here, it will also compile.
            "MMM"
    };

    if (d <= 3) {
        return table[base].substr(0, d);
    } else if(d == 4) {
        return table[base].substr(2, 2);
    } else if (d < 9) {
        return table[base].substr(3, d-4);
    } else {
        return table[base].substr(6, 2);
    }
}

/**
 * @param n The integer
 * @return Roman representation
 */
string intToRoman(int n) {
    string ans;
    int base = 0;
    while (n) {
        int digit = n % 10;

        ans = getBit(digit, base) + ans;

        ++base;
        n /= 10;
    }

    return ans;
}

int main()
{
    int n;
    while (cin >> n) {
        cout << intToRoman(n) << endl;
    }

    return 0;
}
