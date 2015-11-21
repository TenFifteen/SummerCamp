/*
ID: libench1
PROG: pprime
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int x) {
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int reverse(int x) {
    int ans = 0;
    while (x) {
        ans *= 10;
        ans += x%10;
        x /= 10;
    }

    return ans;
}

int start(int len) {
    int ret = 1;
    for (int i = 1; i < len; ++i) {
        ret *= 10;
    }

    return ret;
}

int end(int len) {
    int ret = 9;
    for (int i = 1; i < len; ++i) {
        ret *= 10;
        ret += 9;
    }

    return ret;
}

int shift(int len) {
    int ret = 1;
    for (int i = 0; i < len; ++i) {
        ret *= 10;
    }

    return ret;
}

vector<int> init() {
    vector<int> ans;
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(5);
    ans.push_back(7);

    for (int i = 2; i <= 8; ++i) {
        int s = start(i/2);
        int e = end(i/2);

        if (i % 2) {
            int shi1 = shift(i/2+1);
            int shi2 = shift(i/2);
            for (int j = s; j <= e; ++j) {
                for (int m = 0; m < 10; ++m) {
                    int cur = j*shi1 + m*shi2 + reverse(j);
                    if (isPrime(cur)) {
                        ans.push_back(cur);
                    }
                }
            }
        } else {
            int shi = shift(i/2);
            for (int j = s; j <= e; ++j) {
                 int cur = j*shi + reverse(j);
                 if (isPrime(cur)) {
                     ans.push_back(cur);
                 }
            }
        }
    }

    return ans;
}

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");

    int left, right;
    fin >> left >> right;

    vector<int> ans = init();

    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] >= left && ans[i] <= right) {
            fout << ans[i] << endl;
        }
    }

    return 0;
}
