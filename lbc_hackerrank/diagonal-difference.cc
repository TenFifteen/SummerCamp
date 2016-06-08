#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    long long pri = 0, sec = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            if (i == j) pri += num;
            if (i+j == n-1) sec += num;
        }
    }
    cout << abs(pri-sec) << endl;
    return 0;
}
