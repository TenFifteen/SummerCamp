/**
 * Problem: The Utopian Tree goes through 2 cycles of growth every year. Each
 *          spring, it doubles in height. Each summer, its height increases by 1 meter.
 * Solve: use a static vector to calculate iterator to specific size and then return.
 * Tips: no
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getHeight(int n) {
    static vector<int> h(1, 1);

    if (h.size() < n+1) {
        int t = n + 1 - h.size();
        while (t--) {
            h.push_back((h.size() & 0x1)  == 0 ? h.back() + 1 : h.back() * 2);
        }
    }

    return h[n];
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << getHeight(n) << endl;
    }
    return 0;
}

