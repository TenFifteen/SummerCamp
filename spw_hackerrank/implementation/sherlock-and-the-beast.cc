/**
 * Problem: A Decent Number has the following properties:
 *            Its digits can only be 3's and/or 5's.
 *            The number of 3's it contains is divisible by 5.
 *            The number of 5's it contains is divisible by 3.
 *            If there are more than one such number, we pick the largest one.
 * Solve: factorization
 * Tips: no
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int tn = n;
        while (tn > 0 && tn % 3 != 0) {
            tn -= 5;
        }

        if (tn < 0) {
            cout << -1 << endl;
        } else {
            string fives(tn, '5'), threes(n-tn, '3');
            cout << fives << threes << endl;
        }
    }
    return 0;
}

