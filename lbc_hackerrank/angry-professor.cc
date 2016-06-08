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
        int n, k;
        cin >> n >> k;
        int total = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if (num <= 0) total++;
        }
        if (total < k) cout << "YES" << endl;
        else cout << "NO" << endl;    
    }
    
    return 0;
}
