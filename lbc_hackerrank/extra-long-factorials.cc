#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverse(string &s) {
    if (s.size() < 2) return;
    int left = 0, right = s.size()-1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

string multiply(const string &s, int digit) {
    if (digit == 0) return "0";
    string ans;
    int carry = 0;
    for (int i = s.size()-1; i >= 0; --i) {
        carry += (s[i]-'0') * digit;
        ans.push_back('0' + carry%10);
        carry /= 10;
    }
    if (carry) ans.push_back('0' + carry);
    reverse(ans);
    return ans;
}

string add(const string &s1, const string &s2) {
    string ans;
    int i = s1.size()-1, j = s2.size()-1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
        if (i >= 0) carry += s1[i--] - '0';
        if (j >= 0) carry += s2[j--] - '0';
        ans.push_back('0' + carry % 10);
        carry /= 10;
    }
    if (carry) ans.push_back('0' + carry);
    reverse(ans);
    return ans;
}

string getAnswer(const string &s1, const string &s2) {
    string ans = "0";
    for (int i = 0; i < s2.size(); ++i) {
        ans = add(ans, multiply(s1, s2[i]-'0') + string(s2.size()-i-1, '0'));
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    string ans = "1";
    for (int i = 2; i <= n; ++i) {
        ans = getAnswer(ans, to_string(i));
    }
    cout << ans << endl;
    return 0;
}
