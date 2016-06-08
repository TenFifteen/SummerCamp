/*
一开始犯的错误跟这个博客中说的竟然是一样的http://blog.csdn.net/jimmy0513/article/details/42061523

另外就是没有注意到只需要有ABC三种字符。要不然早就暴力了。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string del(const string &s) {
    vector<bool> flag(s.size(), false);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            flag[i] = true;
            flag[i-1] = true;
        }
    }

    string ans;
    for (int i = 0; i < s.size(); ++i) {
        if (flag[i] == false) ans.push_back(s[i]);
    }
    return ans;
}

int getScore(string s) {
    //cout << "start " << s << endl;
    int ans = 0;
    while (true) {
        //cout << "dealing " << s << endl;
        string ret = del(s);
        if (ret.size() == s.size()) break;
        ans += s.size()-ret.size();
        s = ret;
    }
    //cout << s << " : " << ans << endl;
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int ans = 0;
        for (char ch = 'A'; ch <= 'C'; ++ch) {
            string tmp(1, ch); // "" + ch seems to be wrong
            ans = max(ans, getScore(tmp + s));
        }
        for (int i = 0; i < s.size(); ++i) {
            for (char ch = 'A'; ch <= 'C'; ++ch) {
                ans = max(ans, getScore(s.substr(0, i+1) + ch + s.substr(i+1)));
            }
        }

        cout << ans << endl;
    }

    return 0;
}
