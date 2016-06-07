#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getLengh(int n) {
    int len = 0;
    while (n) {
        len++;
        n /= 10;
    }
    return len;
}

bool isKaprekar(int n) {
    int len = getLengh(n);
    long long square = n;
    square *= n;
    
    int base = 1;
    for (int i = 0; i < len; ++i) {
        base *= 10;
    }
    
    int left = square / base;
    int right = square % base;
    return left + right == n;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int p, q;
    cin >> p >> q;
    bool first = true;
    for (int i = p; i <= q; ++i) {
        if (isKaprekar(i)) {
            if (first) {
                cout << i;
                first = false;
            } else {
                cout << " " << i;
            }
        }
    }
    if (first) cout << "INVALID RANGE";
    cout << endl;
    return 0;
}
