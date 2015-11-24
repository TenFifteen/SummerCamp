/*
ID: libench1
PROG: runround
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

using namespace std;

bool isRun( long long x ) {
    string s = to_string(x);

    vector<int> num(10, 0);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            return false;
        }
        if (num[s[i]-'0'] != 0) {
            return false;
        }
        num[s[i]-'0'] = 1;
    }

    vector<bool> flag(s.size(), false);
    flag[0] = true;
    int cur = 0;
    while (true) {
         int next = cur + s[cur] - '0';
         next %= s.size();

         if (flag[next] == true) {
             cur = next;
             break;
         }
         flag[next] = true;
         cur = next;
    }

    if (cur != 0) {
         return false;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (flag[i] == false) {
            return false;
        }
    }

    return true;
}

int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");

    long long n;
    fin >> n;

    for (int i = n+1; ; ++i) {
        if (isRun(i)) {
            fout << i << endl;
            break;
        }
    }

    return 0;
}
