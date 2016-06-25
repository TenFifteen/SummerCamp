/**
 * Problem: You are given  N sticks, where the length of each
 *          stick is a positive integer. A cut operation is performed
 *          on the sticks such that all of them are reduced by
 *          the length of the smallest stick.
 * Solve: sort + find the count of equal
 * Tips: no
 */

#include <cmath>
#include <cstdio>
#include <list>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> sticks(n);
    for (int i = 0; i < n; ++i) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());

    int s = 0;
    while (s < n) {
        cout << n - s << endl;
        while (++s < n && sticks[s] == sticks[s-1]);
    }

    return 0;
}

