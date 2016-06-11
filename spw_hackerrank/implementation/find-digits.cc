/**
 * Problem: Given an integer, , traverse its digits (1,2,...,n) and
 *          determine how many digits evenly divide  (i.e.: count the
 *          number of times  divided by each digit i has a remainder of ).
 *          Print the number of evenly divisible digits.
 * Solve: judge every digit one by one
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
        int cnt = 0, tn = n;
        while (tn) {
            int d = tn % 10;
            if (d && n % d == 0) ++cnt;
            tn /= 10;
        }

        cout << cnt << endl;
    }
    return 0;
}

