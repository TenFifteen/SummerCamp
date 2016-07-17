#include <string>
#include <iostream>

#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

void multi(string &src, int fac)
{
    if (fac == 0) {
        src = "0";
        return;
    } else if (fac == 1) {
        return;
    }

    int len = src.size();

    string result(len + 1, '0');
    int carry = 0;
    int offset = 1;
    while (offset <= len) {
        int product = (src[len-offset] - '0') * fac + carry;

        result[len+1-offset] = product % 10 + '0';
        carry = product / 10;

        ++offset;
    }
    result[0] = carry + '0';
    if (carry == 0) {
        src = result.substr(1);
    } else {
        src = result;
    }
}

void add(string &src, string dest)
{
    int len1 = src.size();
    int len2 = dest.size();

    int len = max(len1, len2) + 1;
    string result(len, '0');

    int offset = 1;
    int carry = 0;
    while (offset < len) {
        int a = 0, b = 0;
        if (len1 - offset >= 0) a = src[len1-offset] - '0';
        if (len2 - offset >= 0) b = dest[len2-offset] - '0';

        int sum = a + b + carry;
        result[len-offset] = sum % 10 + '0';
        carry = sum / 10;

        ++offset;
    }
    result[0] = carry + '0';
    if (carry == 0) {
        src = result.substr(1);
    } else {
        src = result;
    }
}

string multiply(string num1, string num2)
{
    int sign = 1;
    if (num1[0] == '-') {
        sign = !sign;
        num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
        sign = !sign;
        num2 = num2.substr(1);
    }
    if (num1 == "0" || num2 == "0") return "0";

    string r = "0";
    int len = num1.size();
    int offset = 1;
    while (offset <= len) {
        string num = num2;
        multi(num, num1[len-offset]-'0');

        string zeros(offset-1, '0');
        num += zeros;

        add(r, num);
        offset++;
    }
    if (sign) {
        return r;
    } else {
        return "-" + r;
    }
}

/**
 * Problem: Given two numbers represented as strings, return multiplication of
 *          the numbers as a string. The numbers can be arbitrarily large and
 *          non-negative.
 * Solve: 1. the possible size of product's bit are size1+size2, size1+size2-1
 *           and 0(when there is 0 factor).
 *        2. if we initial the size of product's to size1+size2, the n1[i] * n2[j]
 *           must fall in the r[i+j+1] (because we assign the total size is
 *           size1+size2, then there is must an carry in the last, so the 1 is the
 *           carry offset, or i+j is proper).
 *
 *           0 1 2
 *             0 1 *
 *          --------
 *           1 2 3
 *         0 1 2
 *         --------
 *
 *         becomes
 *
 *           0 1 2
 *             0 1 *
 *          --------
 *           2 3 4
 *         1 2 3
 *         --------
 *         there is an offset of 1 in the place.
 * Tips: see above
 */
string multiply1(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    int len = len1 + len2;

    string result(len, '0');
    for (int i = len1-1; i >= 0; --i) {
        int carry = 0;
        for (int j = len2-1; j >= 0; --j) {
            int tmp = result[i+j+1]-'0' + (num1[i]-'0') * (num2[j]-'0');
            carry = tmp / 10;
            result[i+j+1] = tmp % 10 + '0';
        }
        result[i] += carry;
    }

    int i = 0;
    while (i < len) {
        if (result[i] != '0') break;
        ++i;
    }

    if (i == len) return "0";
    return result.substr(i);
}

int main()
{
    string s, d;
    while (cin >> s >> d) {
        cout << multiply1(s, d) << endl;
    }

    return 0;
}

class Solution {
    public:
        string multiply(string num1, string num2) {
            string ans;
            if (num1.size() > num2.size())
                swap(num1, num2);

            int m = num1.size();
            for (int i = 0; i < m; ++i) {
                ans = add(ans+'0', mul(num2, num1[i]));
            }

            return ans;
        }

        string add(string a, string b)
        {
            int i = a.size() - 1, j = b.size() - 1;

            string ans;
            int carry = 0;
            while (i >= 0 || j >= 0 || carry) {
                if (i >= 0) {
                    carry += a[i] - '0';
                    --i;
                }
                if (j >= 0) {
                    carry += b[j] - '0';
                    --j;
                }

                ans = (char)(carry % 10 + '0') + ans;
                carry /= 10;
            }

            return ans;
        }

        string mul(string a, char c) {
            int fac = c - '0';
            if (fac == 0) return "0";
            else if (fac == 1) return a;

            int i = a.size() - 1;
            string ans;
            int carry = 0;
            while (i >= 0 || carry) {
                if (i >= 0)
                    carry += (a[i] - '0') * fac;

                ans = (char)(carry % 10 + '0') + ans;
                carry /= 10;

                --i;
            }

            return ans;
        }
};
