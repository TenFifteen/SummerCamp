/*
ID: libench1
PROG: preface
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

int getLen(int x) {
    int ans = 0;
    while (x) {
        ans++;
        x /= 10;
    }

    return ans;
}

int getMul(int i) {
    int ans = 1;
    while (i) {
        ans *= 10;
        i--;
    }

    return ans;
}

string getRoman(int n) {
    unordered_map<int, char> um;
    um[1] = 'I';
    um[5] = 'V';
    um[10] = 'X';
    um[50] = 'L';
    um[100] = 'C';
    um[500] = 'D';
    um[1000] = 'M';

    int len = getLen(n);
    string ans;
    for (int i = 0; i < len; ++i) {
        int cur = n % 10;
        n /= 10;
        if (cur < 4) {
            for (int j = 0; j < cur; ++j) {
                ans.push_back(um[getMul(i)]);
            }
        } else if (cur == 4) {
            ans.push_back(um[getMul(i)]);
            ans.push_back(um[getMul(i)*5]);
        } else if (cur < 9) {
            ans.push_back(um[getMul(i)*5]);
            for (int j = 5; j < cur; ++j) {
                ans.push_back(um[getMul(i)]);
            }
        } else {
            ans.push_back(um[getMul(i)]);
            ans.push_back(um[getMul(i+1)]);
        }
    }

    return ans;
}

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");

    int n;
    fin >> n;

    unordered_map<char, int> um;
    for (int i = 1;i <= n; ++i) {
        string ans = getRoman(i);
        for (auto a : ans) {
            um[a]++;
        }
    }
    string index = "IVXLCDM";
    for (auto i : index) {
        if (um[i] != 0) {
            fout << i << " " << um[i] << endl;
        }
    }

    return 0;
}
