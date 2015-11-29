/*
ID: libench1
PROG: fracdec
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a > b) {
        return gcd(b, a);
    }

    if (a == 0) {
        return b;
    }

    return gcd(b%a, a);
}

string getFrac(int n, int d) {
    if (n == 0) {
        return "0";
    }

    string ans;
    unordered_map<int, int> um;

    while (n != 0) {
        n *= 10;
        int cur = n / d;
        n %= d;
        int tmp = cur*100000 + n;

        if (um.find(tmp) != um.end()) {
            return ans.substr(0, um[tmp]) + "(" + ans.substr(um[tmp], ans.size()) + ")";
        }

        ans.push_back(cur+'0');
        um[tmp] = ans.size()-1;
    }

    return ans;
}

int main() {
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");

    int n, d;
    fin >> n >> d;

    int g = gcd(n, d);
    n /= g;
    d /= g;

    int integer = n / d;
    n %= d;

    if (n == 0) {
        fout << integer << ".0" << endl;
    } else {
        string frac = getFrac(n, d);
        string ans = to_string(integer) + "." + frac;
        for (int i = 0; i < ans.size(); i += 76) {
            fout << ans.substr(i, 76) << endl;
        }
    }
    return 0;
}
