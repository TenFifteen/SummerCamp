#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        n %= 7;
        if (n < 2) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    return 0;
}
