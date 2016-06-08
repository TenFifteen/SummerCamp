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
        int n;
        cin >> n;
        int b = 0;
        while (b * 3 <= n) {
            if ((n-b*3)%5 == 0) break;
            b++;
        }
        
        if (b * 3 > n) cout << -1 << endl;
        else {
            for (int i = 0; i < b*3; ++i) cout << 5;
            for (int i = 0; i < n-b*3; ++i) cout << 3;
            cout << endl;
        }
    }
    
    return 0;
}
