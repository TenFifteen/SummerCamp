/*
这道题目的坑在于，数据比较大，用int会溢出。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        long long x, y, z, b, w;
        cin >> b >> w >> x >> y >> z;
        if (x+z < y) {
            cout << (b+w)*x + z*w << endl;
        } else if (y+z < x) {
            cout << (b+w)*y + z*b << endl;
        } else {
            cout << x*b + y*w << endl;
        }
    }
    return 0;
}
