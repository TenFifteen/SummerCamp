#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int palindrom(string &s)  {
    int n = s.size();

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int l = i, r = i;
        while (l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) {
            --l, ++r;
        }
        ans = max(ans, r-l+1);
        //cout << i << " " << l << "--" << r << endl;

        l = i+1, r = i;
        while (l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) {
            --l, ++r;
        }
        //cout << i << " " << l << "--" << r << endl;
        ans = max(ans, r-l+1);
    }

    return ans;
}

// some optimize, when the ans is long enough
// the duplicates
int palindrom2(string &s)  {
    int n = s.size();

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (n - i < ans/2) break;

        int l = i, r = i;
        while (r+1 < n && s[r+1] == s[r]) ++r;
        i = r;

        while (l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) {
            --l, ++r;
        }
        ans = max(ans, r-l+1);
    }

    return ans;
}
// wrong when s = 'aadaadaa'
// that is we only remember one possible case.
int palindrom1(string &s)  {
    int n = s.size();

    vector<int> len(n+1, 1);
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1])
            len[i] = len[i-1] + 1;
    }

    for (int i = 1; i < n; ++i) {
        int j = i - len[i-1] - 1;
        if (j >= 0 && s[i] == s[j])
            len[i] = len[i-1] + 2;

        ans = max(ans, len[i]);
    }

    return ans;
}

string getRandomStr(int len) {
    srand(time(NULL));
    string ans(len, 'a');
    for (int i = 0; i < len; ++i) {
        ans[i] = 'a' + random() % 26;
    }

    return ans;
}

int main()
{
    int n;
    string str;
    cin >> n;
    while (n--) {
        cin >> str;
        cout << str << endl;
        cout << palindrom1(str) << " " << palindrom(str) << endl;
    }

    return 0;
}
