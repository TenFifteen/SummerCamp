/*
这道题用到了15 puzzle定理。
具体证明见：http://blog.csdn.net/mindhawk/article/details/1445013
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        
        int total = 0;
        for (int i = n-2; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                if (nums[j] < nums[i]) total++;
            }
        }
        if (total % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
