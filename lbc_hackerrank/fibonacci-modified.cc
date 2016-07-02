/*
自己实现的大整数，竟然会超时，而java的BigInteger竟然这么高效。
是时候回头看一下java的BigInteger是怎么实现的了。
*/
/*#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(const string &s1, const string &s2) {
    string ans(max(s1.size(), s2.size()) + 1, '0');
    int i1 = s1.size()-1, i2 = s2.size()-1, i3 = ans.size()-1;
    int carry = 0;
    while (i1 >= 0 || i2 >= 0) {
        if (i1 >= 0) carry += s1[i1--] - '0';
        if (i2 >= 0) carry += s2[i2--] - '0';
        ans[i3--] = carry % 10 + '0';
        carry /= 10;
    }
    if (carry) ans[i3--] = carry + '0';
    return ans.substr(i3+1);
}

string mul(const string s, int d) {
    string ans(s.size() + 1, '0');
    int i1 = s.size()-1, i2 = ans.size()-1;
    int carry = 0;
    while (i1 >= 0) {
        carry += (s[i1--]-'0') * d;
        ans[i2--] = carry % 10 + '0';
        carry /= 10;
    }
    if (carry) ans[i2--] = carry + '0';
    return ans.substr(i2+1);
}

string square(const string &s) {
    string ans = "0";
    for (int i = 0; i < s.size(); ++i) {
        string now = mul(s, s[i]-'0') + string(s.size()-i-1, '0');
        ans = add(now, ans);
    }
    return ans;
}

string squareII(const string &s) {
     string ans(s.size()*2, '0');
     for (int i = s.size()-1; i >= 0; --i) {
         int carry = 0, i1 = s.size()-1, i2 = ans.size()-(s.size()-i);
         while (i1 >= 0) {
             carry += (s[i]-'0')*(s[i1--]-'0') + ans[i2]-'0';
             ans[i2--] = carry % 10 + '0';
             carry /= 10;
         }
         if (carry) {
              ans[i2--] = carry + '0';
         }
     }
     int index = 0;
     while (ans[index] == '0') index++;
     return ans.substr(index);
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    string first = to_string(a);
    string second = to_string(b);
    for (int i = 2; i < n; ++i) {
        string next = add(squareII(second), first);
        first = second;
        second = next;
    }
    cout << second << endl;
    return 0;
}*/
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a = new BigInteger(in.next());
        BigInteger b = new BigInteger(in.next());
        int n = in.nextInt();
        for (int i = 2; i < n; ++i) {
            BigInteger next = b.multiply(b).add(a);
            a = b;
            b = next;
        }
        System.out.println(b);
    }
}
