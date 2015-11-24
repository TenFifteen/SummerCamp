/*
ID: libench1
PROG: zerosum
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

bool isZero(vector<char> &ops) {
    int sum = 0;
    int last = 1;
    char lastOP = ' ';
    for (int i = 0; i < ops.size(); ++i) {
        switch(ops[i]) {
            case '+':
                if (lastOP == '+') {
                    sum += last;
                } else if (lastOP == '-') {
                    sum -= last;
                } else {
                    sum = last;
                }
                last = i+2;
                lastOP = '+';
                break;
            case '-':
                if (lastOP == '+') {
                    sum += last;
                } else if (lastOP == '-') {
                    sum -= last;
                } else {
                    sum = last;
                }
                last = i+2;
                lastOP = '-';
                break;
            case ' ':
                last *= 10;
                last += i+2;
                break;
        }
    }

    if (lastOP == '+') {
        sum += last;
    } else if (lastOP == '-') {
        sum -= last;
    } else {
        sum = last;
    }

    return sum == 0;
}

void search(int n, int cur, vector<char> &ops, vector<string> &ans) {
    if (cur == n) {
        if (isZero(ops)) {
            string tmp;
            tmp.push_back('1');
            for (int i = 0; i < ops.size(); ++i) {
                tmp.push_back(ops[i]);
                tmp.push_back(i+'2');
            }
            ans.push_back(tmp);
        }
        return;
    }

    string token = " +-";
    for (int i = 0; i < 3; ++i) {
        ops.push_back(token[i]);
        search(n, cur+1, ops, ans);
        ops.pop_back();
    }
}

int main() {
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");

    int n;
    fin >> n;

    vector<string> ans;
    vector<char> ops;
    search(n, 1, ops, ans);

    for (int i = 0; i < ans.size(); ++i) {
        fout << ans[i] << endl;
    }

    return 0;
}
