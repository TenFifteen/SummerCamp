/**
 * Problem: calculate count of all the square number  between a and b
 * Solve: just iterator from square(a)
 * Tips: see comments below.
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getCount(int a, int b) {
    int i = sqrt(a), cnt = 0;
    if (i*i == a) ++cnt;
    // plus 1 whether i*i == a or not
    ++i;

    while (i*i <= b) {
        ++cnt;
        ++i;
    }

    return cnt;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << getCount(a, b) << endl;
    }
    return 0;
}

