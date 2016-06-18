#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    while (cin >> T) {
        for (int i = 0; i < T; ++i) {
            unsigned num;
            cin >> num;
            cout << ~num << endl;
        }
    }
    return 0;
}
