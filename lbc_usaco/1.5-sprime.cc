/*
ID: libench1
PROG: sprime
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isPrime(int x) {
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> getPrimes(int n) {
    vector<int> ans;
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(5);
    ans.push_back(7);

    for (int i = 2; i <= n; ++i) {
        vector<int> next;
        for (int j = 0; j < ans.size(); ++j) {
            for (int k = 1; k < 10; k += 2) {
                int cur = ans[j]*10 + k;
                if (isPrime(cur)) {
                    next.push_back(cur);
                }
            }
        }

        ans.swap(next);
    }

    return ans;
}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");

    int n;
    fin >> n;

    vector<int> ans = getPrimes(n);

    for (int i = 0; i < ans.size(); ++i) {
        fout << ans[i] << endl;
    }

    return 0;
}
